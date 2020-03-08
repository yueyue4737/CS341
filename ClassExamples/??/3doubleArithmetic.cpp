// Copyright YL liuyue2@bu.edu 10/19/2019
// Basic Double Arithmetic

#include <iostream> 
using namespace std;

int main() 
{
    double a = 1.2, b = 2.3, c; // dpuble-precision variable
    c = a / b;
    cout << "The quotient of a over b equals: " << c << endl;
    c = a / 0;
    cout << "The quotient of a over 0 equals to: " << c << endl;
    cout << "Value of c = " << c << endl;
    b = a / c;
    cout << "The quotient of b = a / c equals: " << b;
    c = b + 2 / a - 3;
    cout << "The result of this Polynomial without parentheses is: " << c << endl;
    c = (b + 2) / (a - 3);
    cout << "The result of this Polynomial with parentheses is: " << c << endl;
    return 0;
}