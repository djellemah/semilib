#pragma warning(disable: 4786)

#include <iostream>
#include <string>


#include "Regex.h"

using namespace std;
using namespace semilib;

int main ( int argc, char * argv[] )
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
		cout << "Subexpression 0 - the whole matched string: " + regexString << endl;
		string temp = regex[0];
		cout << temp << endl;
		cout << "Should be FORMS=TECE13," << endl;
		cout << "Subexpression 1 - " + subexpression << endl;
		temp = regex[1];
		cout << temp << endl;
		cout << "Should be 13" << endl;

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

