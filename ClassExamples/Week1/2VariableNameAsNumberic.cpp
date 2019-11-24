// Location
//  64-bit systems use size_t instead of int

#include <iostream>
using namespace std;

int main() {
	// display location of a single variable and its content
	int x = 10;
	cout << "Location of x is at " << &x << " and contains " << x << endl;
	cout << "Location of x+1 is at " << &x+1 << " and contains " << *(&x + 1) 
		<< endl;

	int array[5] { 0, 1, 2, 3, 4 };   
	
	// display location of arrary elements and its contents
	cout << "Location of first element of array is at " << array << endl;

	// display contents of arrary elements and its contents
	int i, j;
	cout << "Array contains ";
	for (i = 0; i < 5; i++)			 
		cout << array[i] << " ";
	cout << endl;
	for (j = -10; j < 10; j++)		 
		cout << array[j] << " ";	 
	cout << endl;					 
	return 0;
}
