#pragma warning(disable: 4786)

#include <iostream>
#include <string>

using namespace std;

#include "Regex.h"

//#include "Thread.h"

int main ()
{
	string subexpression = "([L1][1345])";
	string regexString = "FORM[AST]*=T[A-Z]*" + subexpression + ",";
	Regex regexNo ( regexString, REG_NOSUB | REG_EXTENDED );
	Regex regex ( regexString );

	string aString ( "FORMS=TECE13,FORMAT=TECE13,END;" );

	cout << regex << endl;
	cout << regexNo << endl;

	try
	{
		cout << "Does it match FORMS=TECE13,FORMAT=TECE13,END;?" << endl;
		cout << boolalpha << regex.match ( aString ) << endl;
		cout << "Subexpression 0 - the whole matched string." + regexString << endl;
		cout << regex[0] << endl;
		cout << "Subexpression 1 - " + subexpression << endl;
		cout << regex[1] << endl;

		try
		{
			cout << "Should get exceptions asking for subexpression 2, even though subexps are turned on." << endl;
			cout << regex[2] << endl;
		}
		catch ( exception & e )
		{
			cerr << e.what() << endl;
		}

	}
	catch ( exception & e )
	{
		cerr << e.what() << endl;
	}


	try
	{
		cout << "Testing Regex with REG_NOSUB." << endl;

		cout << "Does it match FORMS=TECE13,FORMAT=TECE13,END;?" << endl;
		cout << boolalpha << regexNo.match ( aString ) << endl;

		cout << "Should get exceptions asking for subexpression 0." << endl;
		cout << regexNo[0] << endl;
	}
	catch ( exception & e )
	{
		cerr << e.what() << endl;
	}

	try
	{
		cout << "Should get exceptions asking for subexpression 1." << endl;
		cout << regexNo[1] << endl;
	}
	catch ( exception & e )
	{
		cerr << e.what() << endl;
	}

	return 0;
}
