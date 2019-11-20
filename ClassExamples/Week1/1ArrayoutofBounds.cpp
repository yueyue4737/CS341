// 19fall CS341 Week1 
// C++ does not bounds checking for fixed-length arrarys

#include <iostream>
using namespace std;

int main() {
	int array[5] { 0, 1, 2, 3, 4 };// declare an arrary of five numbers & assign values to each								 
	int i, j;
        
	// display original array
	for (i = 0; i < 5; i++)			 
		cout << array[i] << " ";
	cout << endl << endl;
	
	// add five locations on either sides of the original array
	for (i = -5; i < 10; i++)		 
		cout << array[i] << " ";	 
	cout << endl;	
	
	return 0;
}
