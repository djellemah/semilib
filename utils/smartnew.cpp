#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "StaticInit.h"

/**
	\defgroup memory Memory Allocation

	Possibly broken c++ memory allocation algorithms. Not linked into the lib, but link this
	file to your application to use it. There has been some trouble with
	using this instead of the win32 api allocators in dlls. Never tried
	it with .so dynamic libraries.
	
	It was originally from an article on memory allocation at Dr Dobbs Journal, I think.
	\@{
*/
//  Policy configuration
const size_t granularity_bits = 2;
const size_t granularity = 1 << granularity_bits;
const size_t page_size_bits = 12;
const size_t page_size = 1 << page_size_bits;
const size_t metapage_size_bits = 8;
const size_t metapage_size = 1 << metapage_size_bits;

size_t handled_obj_size(size_t page_free_size)
{
	return page_free_size;
}

/// utility methods
template<class T>
inline T align_up(T val, size_t alignment)
{
	return(val + alignment-1) & ~(alignment-1);
}

/// utility methods
template<class T>
inline T align_down(T ptr, size_t alignment)
{
	return ptr & ~(alignment-1);
}

struct Header
{
	Header()
		: next ( 0 )
	{
	}

	Header* next;

	bool is_empty() const
	{
		return next == 0;
	}

	Header* deque()
	{
		Header* result = next;
		next = result->next;
		return result;
	}

	void enque(Header* obj)
	{
		obj->next = next;
		next = obj;
	}
};

const short int INITIAL_VALUE = 23466;

struct Page
{
	Page()
	: prev ( 0 )
	, next ( 0 )
	, alloc_count ( 0 )
	, alloc_size ( 0 )
	, unallocated ( 0 )
	, initialised ( INITIAL_VALUE )
	{
	}
	
	// make sure we're initialised
	short int initialised;

	// Linked list handling
	Page* prev;
	Page* next;
	bool is_empty()
	{
		return next == this;
	}
	
	void link(Page* page)
	{
		page->next = next;
		page->prev = this;
		next->prev = page;
		this->next = page;
	}
	
	void unlink()
	{
		next->prev = prev;
		prev->next = next;
	}
	
	void check_init()
	{
		if ( prev == 0 ) prev = next = this;
	}
	
	// Object allocation handling
	size_t alloc_size;
	size_t alloc_count;
	Header free_list;
	void* unallocated;

	bool is_page_full() const
	{
		return free_list.is_empty() && unallocated == 0;
	}
	
	bool is_page_empty() const
	{
		return alloc_count == 0;
	}
	
	void* allocate()
	{
		alloc_count++;
		if ( !free_list.is_empty() )
			return(void*)free_list.deque();
		void* obj = unallocated;
		unallocated = get_next_obj(unallocated);
		if ( (size_t)unallocated > (size_t)get_last_obj() )
			unallocated = 0;
		return obj;
	}

	void free(void* obj)
	{
		alloc_count--;
		free_list.enque((Header*)obj);
	}

	void designate(size_t size)
	{
		alloc_size = size;
		alloc_count = 0;

		free_list.next = 0;
		unallocated = get_first_obj();
	}

	//  Big allocation
	bool is_big_alloc()
	{
		return alloc_size == 0;
	}

	void* big_alloc(void* place)
	{
		alloc_size = 0;
		unallocated = place;
		return get_first_obj();
	}

	void* big_free()
	{
		return unallocated;
	}
	
	bool is_initialised() const
	{
		return initialised == INITIAL_VALUE;
	}

private:
	void* get_first_obj() const
	{
		return(void*)align_up(sizeof(Page) + (ptrdiff_t)this, granularity);
	}
	void* get_last_obj() const
	{
		return(void*)align_down(page_size - alloc_size + (ptrdiff_t)this, granularity);
	}
	void* get_next_obj(void* obj) const
	{
		return(void*)(alloc_size + (size_t)obj);
	}
};

/**
	this is quite a broken allocator, but it'll work
	for the purposes of allocating the first Header
	object
*/
class Alloc
{
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef Header *pointer;
    typedef const Header *const_pointer;
    typedef Header& reference;
    typedef const Header& const_reference;
    typedef Header value_type;

    pointer address(reference x) const
	{
		return &x;
	}

    const_pointer address(const_reference x) const
	{
		return &x;
	}

    Alloc()
	{
	}

    Alloc operator=(const Alloc)
	{
	}

    pointer allocate(size_type n, const void *hint)
	{
		return reinterpret_cast<pointer>(malloc ( n ) );
	}

    void deallocate(pointer p, size_type n)
	{
		free (p);
	}

    void construct(pointer p, const Header& val)
	{
		new ((void*)p) Header( val );
	}

    void destroy(pointer p)
	{
		p->Header::~Header();
	}

    size_type max_size() const
	{
		return 10000;
	}
};

struct PagePool : protected StaticInit<Header, Alloc>
{
	// redirect these to the StaticInit member
	inline static Header & getFreeList()
	{
		return getStaticItem();
	}

public:
	static Page* allocate()
	{
		if ( getFreeList().is_empty() )	allocate_metapage();
		Header* page = getFreeList().deque();
		return(Page*)page;
	}

	static void free(Page* page)
	{
		getFreeList().enque((Header*)page);
	}
	
private:
	static void allocate_metapage()
	{
		size_t num_pages = metapage_size;
		void* metapage = malloc(num_pages * page_size);
		assert(metapage != 0);
		void* aligned_metapage = (void*)align_up((ptrdiff_t)metapage, page_size);
		if ( metapage != aligned_metapage )
			num_pages -= 1;
		void* curr_page = aligned_metapage;
		for ( size_t i=0; i<num_pages; ++i )
		{
			getFreeList().enque((Header*)curr_page);
			curr_page = (void*)((size_t)curr_page + page_size);
		}
	}
};

const size_t num_sizes = page_size / granularity;
const size_t page_free_space = page_size - sizeof(Page);

Page page_lists[num_sizes];

inline size_t free_list_index(size_t val, size_t alignment)
{
	return val / alignment;
}

void* operator new(size_t size) throw ( std::bad_alloc )
{
	if ( size < 0 )	return 0;
	if ( size == 0 ) size = 1;
	size = align_up(size, granularity);

	if ( size >= handled_obj_size(page_free_space) )
	{
		// This is a "big" allocation
		void* place = malloc(size+page_size+sizeof(Page));
		if ( place == 0 )
		{
			return 0;
		}
		Page* page = (Page*)align_up((ptrdiff_t)place, page_size);
		return page->big_alloc(place);
	}

	Page& header = page_lists[ free_list_index(size, granularity) ];
	header.check_init();
	if ( header.is_empty() )
	{
		Page* free_page = PagePool::allocate();
		header.link(free_page);
		free_page->designate(size);
	}
	Page* free_page = header.next;
	void* obj = free_page->allocate();
	if ( free_page->is_page_full() )
	{
		free_page->unlink();
	}
	return obj;
}

void operator delete(void* ptr)
{
	if ( ptr == 0 )	return;
	Page* page = (Page*)align_down((ptrdiff_t)ptr, page_size);
	if ( !page->is_initialised() )
	{
		return;
	}
	if ( page->is_big_alloc() )
	{
		void* place = page->big_free();
		free(place);
		return;
	}
	if ( page->is_page_full() )
	{
		page->free(ptr);
		if ( page->is_page_empty() )
			PagePool::free(page);
		else
		{
			Page& header = page_lists[ free_list_index(page->alloc_size,granularity) ];
			header.link(page);
		}
		return;
	}
	else
	{
		page->free(ptr);
		if ( page->is_page_empty() )
		{
			page->unlink();
			PagePool::free(page);
		}
	}
}
/**
	\@}
*/
