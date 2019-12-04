
#include <iostream>   
using namespace std;  

int main()  
{
	int ct = 0;
	double nr;
	double sum = 0;
	// Initial user prompt
	cout << "Enter your numbers one at a time, and hit the Enter button after each." << endl;
	while (!cin.eof() && cin.good()) 
	{
		cout << "Enter a number >";
		cin >> nr;
		if (!cin.eof() && cin.good()) {
			sum += nr;
			ct++;
		}
	}
	if (!cin.eof() && !cin.good()) { 
		cout << "Invalid data entered." << endl;
		}	
	cout << "Sum = " << sum << " and Count = " << ct << endl;
	if (ct > 0) 
		cout << "Average = " << sum / ct << endl;
	return 0;
}
