#include <iostream>
#include <functional>

#include "SingleResult.h"
#include "MultiResult.h"

using namespace std;

int main()
{
	try
	{
		SingleResult<int, not_equal_to<int> > result;
		cout << result << endl;
		result = -1;
		result << 1;
		cout << result << endl;
		result = 0;
		result = 1;
	}
	catch ( exception & e )
	{
		cout << "SingleResult" << endl;
		cout << "Caught result exception: " << e.what() << endl;
	}
	
	try
	{
		MultiResult<int> result;
		result << 1 << 2;
		
		// should be fine
		result = 0;
		
		result >> 2;
		
		result = 2;
		
		// should throw exception
		result = 1;
	}
	catch ( exception & e )
	{
		cout << "MultiResult" << endl;
		cout << "Caught result exception: " << e.what() << endl;
	}
	
}
