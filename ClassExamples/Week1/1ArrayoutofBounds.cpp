// 19fall CS341 Week1 
// C++ does not bounds checking for fixed-length array

#include <iostream>
using namespace std;

int main() {
	int array[5] { 0, 1, 2, 3, 4 }; // declare an array of five numbers & assign values to each								 
	int i, j;
        
	// display original array
	for (i = 0; i < 5; i++)			 
		cout << array[i] << " ";
	cout << endl << endl;
	
	// add five locations on either sides of the original array
	for (j = -5; j < 10; j++)		 
		cout << array[j] << " ";	 
	cout << endl; // Q.E.D
	
	return 0;
}
