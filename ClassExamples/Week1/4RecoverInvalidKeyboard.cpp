// recover from bad input numeric data
// calculate sum, count and average

#include <iostream> // include library
using namespace std; // using statement

// global area

int main () {
	// Initializing
	double sum = 0;  
	int count = 0;
	double nr;    // user input
	cout << "Enter your numbers one at a time and hit Enter. Terminate with ctrl-z" << endl;
	while (!cin.eof()) {  // loop control
		cin >> nr;
		if (!cin.eof() && cin.good()) { // test !cin.eof() again in case the user enter EOF in the cin
			sum += nr; 
			count++; // only count valid input
		}
		else if (!cin.eof() && !cin.good()) {
			cout << "Invalid Input, Try Again!" << endl;
			cin.clear(); // clear the cin status bits     
			cin.ignore(256, '\n');  // clear the input buffer up to the newline character
		}   
	}
	// for program termination
	if (count == 0) { 
		cout << "No valid data entered." << endl;
	}
	else {
		cout << "The sum is " << sum << endl
			 << "The average is " << sum / count << endl;
	}
	return EXIT_SUCCESS;
}
