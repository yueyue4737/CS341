// recursiveFibonacci2.cpp CS341 Fall 2010  John Maslanka
// This program demonstrates the development of Fibonacci numbers
// by using recursion

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
		//cout << " x = " << x << "  ct = " << ct << endl;
		int y, z;
		//cout << "About to enter first fibonacci" << endl;
		y = fibonacci(x - 1, ct);
		//cout << "About to enter second fibonacci" << endl;
		z = fibonacci(x - 2, ct);
		output = y + z;
		//cout << "y = " << y << "  z = " << z << endl;
	}
	//cout << "  output = " << output << "  ct = " << ct << endl;
	return output;
}
