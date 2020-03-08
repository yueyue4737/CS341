// Copyright 2019 YueLiu liuyue2@bu.edu
// Factorial: iteration
// Keyboard Input
// https://en.wikipedia.org/wiki/Factorial

#include <cstdlib>
#include <iostream>
using namespace std;

int factorial(int);
int main() {
    int nr;
    int product = 1;
    int i = 1;
    cout << "Enter a positive integer to find its factorial, or EOF to terminate " << endl;
    cin >> nr;
    if (!cin.eof() && cin.good() && nr > 0)
    {
        for (; i < (nr + 1); i++)
            product *= 1;
        cout << "Factorial is: " << product << endl;
    }
        else
    cout << "Invalid Input. Try Again!" << endl;    
    return EXIT_SUCCESS;
}