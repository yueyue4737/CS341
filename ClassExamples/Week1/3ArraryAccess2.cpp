// 

#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
	int Array[10] = { 0,1,2,3,4,5,6,7,8,9 };  											  
	int* Arr = Array;
	cout << (int)Arr << endl;
	int i, n;
	
	for (i = 0; i < 10; i++)
		cout << " " << Array[i];
	cout << endl;
	for (n = 0; n < 10; n++)
		cout << " " << *(Array + n);
	cout << endl;
	for (n = 5, i = 0; i < 6; i++)
		cout << " " << (Array + n)[i];
	cout << endl;
	for (n = 5, i = 0; i > -10; i--)
		cout << " " << (Array + n)[i];
	cout << endl;
	return 0;
}
