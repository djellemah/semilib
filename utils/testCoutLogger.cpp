#include <iostream>
#include <string>

#include "CoutLogger.h"

using namespace std;
using namespace semilib;

int main()
{
	CoutLogger other;
	other << "This is an instance of the CoutLogger" << elog;
	return 0;
}
