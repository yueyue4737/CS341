
#include <iostream>
#include <cstdlib>
using namespace std;

int factorial (int);

int main () {
	int nr;
	cout << "Enter a positive integer for which to calculate its factorial: ";
	cin >> nr;
	if (!cin.eof() && cin.good() && nr > 0 && nr < 14)
  
		cout << "Factorial is " << factorial(nr) << endl; 
	else
		if (cin.good() && (nr <= 0 || nr > 13)) 
			cout << "Value entered is less than or equal to 0 or greater than 14." << endl;
		else if (!cin.good())
			cout << "Invalid input value." << endl;
	return EXIT_SUCCESS;
}
int factorial (int x) { 
	int y = 1;  
	cout << x << endl;
	if (x > 1)  
		y = factorial(x - 1);  
	cout << x*y << endl; 
	return x*y;  
}
