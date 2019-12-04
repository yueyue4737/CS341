

#include <iostream>
using namespace std;

int fibonacci(int, int&);

int main()
{
	int ino, ct = 0;
	cout << "This program calculates a Fibonacci number recursively. " << endl;
	cout << "Enter an integer number >= 2 and <= 30 followed by <Enter>: ";
	cin >> ino;
	if (!cin.eof() && cin.good() && ino <= 30 && ino > 1) {
		int i = 0;
		cout << "Fibonacci number is " << fibonacci(ino, i) << ". ";
		cout << "Count of entries into fibonacci function is " << i << endl;
	}
	else
		if (!cin.eof()) cout << "Invalid input value" << endl;
	return 0;
}
int fibonacci(int x, int& ct) {
	++ct;
	int output = 1;
	if (x > -1) {
		int y, z;
		y = fibonacci(x - 1, ct);
		z = fibonacci(x - 2, ct);
		output = y + z;
	}
	return output;
}
