// Copyright 2019 YueLiu liuyue2@bu.edu
// Textbook Chapter 9
// Fibonacci: recursion

#include <cstdlib>
#include <iostream>
using namespace std;

int fibonacci(int);

int main()
{   
    int ino, ct = 0;
    cout << "Please enter the Fibonacci number you wish to see.";
    cout << "Enter an integer number greater than 0 followed by <Enter> ";
    cin >> ino;
    if (!cin.eof() && cin.good() && ino > 1) {
        cout << "Fibonacci numbers are: ";
        for (int i = 0; i < ino; i++) {
            cout << fibonacci(i) << " ";
        }
    }
    else 
            cout << "Invalid Input Value";
    cout << endl;
    cout << "Program Terminating" << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
int fibonacci (int x) {
    if (x > 1)
        return (fibonacci (x - 2) + fibonacci (x - 1));
    return 1;
}