//  

#include <iostream>
using namespace std;

int main() {
	int x = 10;
	cout << "Location of x is at " << &x << " and contains " << x << endl;
	cout << "Location of x+1 is at " << &x+1 << " and contains " << *(&x + 1) 
		<< endl;

	int array[5] { 0, 1, 2, 3, 4 };   
									 
	cout << "Location of first element of array is at " << array << endl;

	int i, j;
	cout << "Array contains ";
	for (i = 0; i < 5; i++)			 
		cout << array[i] << " ";
	cout << endl;
	for (i = -10; i < 10; i++)		 
		cout << array[i] << " ";	 
	cout << endl;					 
	return 0;
}
