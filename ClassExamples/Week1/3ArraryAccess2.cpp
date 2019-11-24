// create a static array and access the elements in three ways
// using a combination of array name, integer displacement and indexing

#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
	int Array[10] = { 0,1,2,3,4,5,6,7,8,9 };  											  
	int* Arr = Array;
	cout << (int)Arr << endl;
	int i, n;
	
	// using array name and an index
	for (i = 0; i < 10; i++)
		cout << " " << Array[i];
	cout << endl;
	
	// using indirection with the array name plus an index
	for (n = 0; n < 10; n++)
		cout << " " << *(Array + n);
	cout << endl;
	
	// to process an array from an intermediate point to the end 
	for (n = 5, i = 0; i < 6; i++)
		cout << " " << (Array + n)[i];
	cout << endl;
	
	for (n = 5, i = 0; i > -10; i--)
		cout << " " << (Array + n)[i];
	cout << endl;
	        system("PAUSE") // in case your system expects a PAUSE before ending
	return 0;
}
