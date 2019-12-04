
#include <iostream>
using namespace std;

int fibonacci(int);

int main()
{
	int ino;
	cout << "This program calculates a Fibonacci number recursively. " << endl;

	cout << "Enter an integer number >= 0 and <= 30 followed by <Enter>: ";
	cin >> ino;
	if (!cin.eof() && cin.good() && ino <= 30 && ino >= 0) { 
		cout << "Fibonacci number is " << fibonacci(ino) << endl;
	}
	else
		if (!cin.eof()) 
			cout << "Invalid input value" << endl;
	return 0;
}
int fibonacci(int x) {
	int output = 1;
	if (x > 1) {
		int y, z;
		y = fibonacci(x - 1);
		z = fibonacci(x - 2);
		output = y + z;
	}
	return output;
}
