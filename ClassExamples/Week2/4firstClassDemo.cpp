// Basic Structure of a class

#include <iostream>
using namespace std;
#include "FirstClass.h"
int main() {
	cout << "Welcome to the FirstClassDemo program" << endl;
	FirstClass A;
	A.putNr(5);
	cout << "Value of nr data member  in A object is "
		<< A.getNr() << endl;
	return EXIT_SUCCESS;
}
