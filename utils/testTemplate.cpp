#include "Template.h"

#include <string>
#include <map>
#include <iostream>
#include <iterator>

using namespace std;
using namespace semilib;

int main ( int /*argc*/, char * /*argv[]*/ )
{
	map<string,string> values;
	values["cause"] = "Charity";
	values["village"] = "Ikageng";
	values["variable"] = "Always and Always";
	values["value"] = "Never";
	values["ever"] = "Ever";
	values["extra"] = "Spice";
	values["1"] = "PO";
	values["2"] = "Box";

	Template one ( "$variable should be ${value} for $(ever) and $1$2" );
#if 0
	copy (
		one.chunks().begin()
		, one.chunks().end()
		, ostream_iterator<string> ( cout, "\n" )
	);
#endif
	cout << one.subst ( values ) << endl;

	Template two ( "give $$10 to $cause from ${village}folk" );
#if 0
	copy (
		two.chunks().begin()
		, two.chunks().end()
		, ostream_iterator<string> ( cout, "\n" )
	);
#endif
	cout << two.subst ( values ) << endl;
	
	try
	{
		Template three ( "$nothing" );
#if 0
		copy (
			three.chunks().begin()
			, three.chunks().end()
			, ostream_iterator<string> ( cout, "\n" )
		);
#endif
		cout << three.subst ( values ) << endl;
	}
	catch ( exception & e )
	{
		cout << "Three did indeed fail: " << e.what() << endl;
	}

	return 0;
}
