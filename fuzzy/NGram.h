#ifndef NGram_h
#define NGram_h

#include <utility>
#include <string>

using namespace std;

#include "fuzzy.h"
#include "fuzzydlldef.h"

class FUZZY_DLL_API NGram
{
public:
	// construct this with a particular length, then call match
	// longer length means the words must correspond more closely
	NGram ( int defaultLength = 3 )
		: length ( defaultLength )
	{
	}

	/*
		pair.first contains the ngram match value for this string
		pair.second contains the largest possible ngram value match for this string
	*/
	pair<int,int> match ( const string & a, const string & b )
	{
		if ( a.length() < b.length() )
			return doMatch ( a,b );
		else
			return doMatch ( b,a );
	}

	bool operator < ( const NGram & other ) const
	{
		return length < other.length;
	}

	bool operator == ( const NGram & other ) const
	{
		return length == other.length;
	}

protected:
	// find a percentage match of a in b
	// length of b should be less than length of a

	/**
		pair.first contains the ngram match value for this string
		pair.second contains the largest possible ngram value match for this string
	*/
	pair<int,int> doMatch ( const string & b, const string & a );

private:
	int length;
};


#endif
