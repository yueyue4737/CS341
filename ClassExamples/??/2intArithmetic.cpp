// Copyright YL liuyue2@bu.edu 10/19/2019
// Basic Integer Arithmetic

#include <iostream> // provide iostream library for compiler
using namespace std; // provide definitions of standard symbols for compiler

int main()
{
    int a = 1, b = 2, c; // Define three int variables: two are initialized
    c = a + b;
    cout << "The sum of the two integer is:" << c << endl; // produce the sum to the user with surrounding explanation and neatness
    system("pause");
    cout << "The answer was truncated to 0 because of the integer divide." << endl;
    double d;
    d = (double) a / b; // d is a cast
    cout << "Using the cast, the quotient of a over b is:" << d << endl;
    system("pause");
    c = a / 0;
    cout << "Quotient = " << c << endl;
    cout << "int Division by 0 is not allowed." << endl;
    return 0;
}