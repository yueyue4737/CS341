
#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
	int i; int j;
	int* Arr; 
	Arr = new (int[5]); 
	if (Arr != NULL) {
		cout << "Value in variable Arr points to the location " << (int)Arr << endl;
		for (i = 0; i < 5; i++) {  
			*(Arr + i) = (i + 1) * i;
		}
		cout << "First array is ";
		for (j = 0; j < 5; j++) 
			cout << *(Arr + j) << " ";
		cout << endl;
		cout << "Value in variable Arr points to Heap location " << (int)Arr << endl;
		cout << "Location of i is " << int(&i) << endl;
		cout << "Location of j is " << int(&j) << endl;

		int* temp; 
		temp = new (int[10]);  
		if (temp != NULL) {  
			cout << "Reference to new Heap is " << (int)temp << endl;
			for (i = 0; i < 5; i++) {
				*(temp + i) = *(Arr + i); 
			}
			for (i = 5; i < 10; i++) {
				*(temp + i) = (i + 1) * i;
			}
			delete[] Arr; 
			Arr = temp; 
			cout << "New array is ";
			for (j = 0; j < 10; j++)  
				cout << *(Arr + j) << " ";
			cout << endl;
			cout << "Value in variable Arr points to the location " << (int)Arr << endl;
			cout << "Location of i is " << int(&i) << endl;
			cout << "Location of j is " << int(&j) << endl;
		}
		else
			cout << "Insufficient Heap resource." << endl; 
	}
	else
		cout << "Insufficient Heap resource." << endl; 
	return 0;
}
