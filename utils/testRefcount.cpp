#include <iostream>
#include <string>

#include "RefCount.h"

using namespace std;
using namespace semilib;

int main()
{
	long * ptr = new long;
	*ptr = 12345;
	RefCount<long> value = ptr;
	{
		RefCount<long> copy = value;
		cout << "copy: " << value << endl;
	}
	cout << "value: " << value << endl;
}
