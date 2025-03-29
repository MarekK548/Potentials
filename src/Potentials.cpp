// Potentials.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "GaussianElement.h"

using namespace std;

int main()
{
	GaussianElement test{ 0, {0,0}, 1, 0 };
	test.getValue({0,0}, 1);
	cout << "Hello CMake." << endl;
	return 0;
}
