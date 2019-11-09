// 

#include <iostream>
using namespace std;

int main() {
	int array[5] { 0, 1, 2, 3, 4 };  
									 
	int i, j;

	for (i = 0; i < 5; i++)			 
		cout << array[i] << " ";
	cout << endl << endl;
	for (i = -5; i < 10; i++)		 
		cout << array[i] << " ";	 
	cout << endl;					 
	return 0;
}
