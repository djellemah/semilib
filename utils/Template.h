#ifndef Template_h
#define Template_h

#include <string>
#include <vector>
#include <map>

namespace semilib
{

class Chunk
{
public:
	virtual ~Chunk() {};
		
	/// the name of the chunk. Will only apply to variables.
	virtual std::string name() const = 0;

	/// the original value of the chunk
	virtual std::string value() const = 0;

	/// the replacement value of the chunk
	virtual std::string replacement() const = 0;

	virtual bool isVariable() const = 0;
};

std::ostream & operator << ( std::ostream & os, const Chunk * );
std::ostream & operator << ( std::ostream & os, const Chunk & );

class Text : public Chunk
{
public:
	Text ( const std::string & value );
	virtual ~Text();

	virtual std::string name() const;

	/// the original value of the chunk
	virtual std::string value() const;

	/// the replacement value of the chunk
	virtual std::string replacement() const;

	virtual bool isVariable() const
	{
		return false;
	}
	
private:
	std::string _value;
};

class Variable : public Chunk
{
public:
	Variable ( const std::string & name );

	virtual ~Variable();

	virtual std::string name() const;

	/// the original value of the chunk
	virtual std::string value() const;

	/// the replacement value of the chunk
	virtual std::string replacement() const;

	virtual bool isVariable() const
	{
		return true;
	}
	
private:
	std::string _name;
};

/**
	How annoying, to have a language that can't do variable interpolation
	in strings, and doesn't have a library for it either.
*/
class Template
{
public:
	typedef std::vector<Chunk*> Chunks;
	
	Template ( const std::string & rhs );
	~Template();
	
	std::string subst ( std::map<std::string,std::string> values ) const;
	std::string subst ( const std::string & key, const std::string & value ) const;

	const Chunks & chunks() const
	{
		return _chunks;
	}

protected:
	void parse();

private:
	std::string _template;
	Chunks _chunks;
};

}

#endif
