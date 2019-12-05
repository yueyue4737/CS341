// count the frequency and calculate the sum of the number
// test the validation

#include <iostream>   // provide iostream library for inputs, outputs and their testing
using namespace std;  // provide definitions of standard symbols for compile

int main()  
{
	int ct = 0;
	double nr;
	double sum = 0;
	// Initial user prompt
	cout << "Enter your numbers one at a time, and hit the Enter button after each." << endl;
	while (!cin.eof() && cin.good())  // loop control, terminate when cin.eof()/cin.bad()
	{
		cout << "Enter a number >";
		cin >> nr;
		if (!cin.eof() && cin.good()) { // not dupulication, this is for individual valid data
			sum += nr;
			ct++;
		}
	}
	if (!cin.eof() && !cin.good()) { // for terminating
		cout << "Invalid data entered." << endl;
		}	
	cout << "Sum = " << sum << " and Count = " << ct << endl;
	if (ct > 0) 
		cout << "Average = " << sum / ct << endl;
	return 0;
}
