#include "PredicateResult.h"

#include <iostream>
#include <functional>

using namespace std;

int main()
{
	try
	{
		PredicateResult<int, not_equal_to<int>, 0 > result;
		result = 0;
		result = 1;
	}
	catch ( exception & e )
	{
		cout << "Caught result exception: " << e.what() << endl;
	}
}
