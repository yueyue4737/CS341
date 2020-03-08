// Copyright YL liuyue2@bu.edu 10/19/2019
// Evaluate the conditional expressions

#include <iostream>;
using namespace std;

int main() {
    int a = 1, b = 2;
    bool test;
    // simple conditions
    test = !(a == b);
    cout << "(a != b)" << test << endl; // negated condition
    test = (b);  // b != 0
    cout << "(b)" << test << endl; // abbreviated condition
    test = !(b); // !(b != 0)
    cout << "!(b)" << test << endl; 
    // compound conditions
    double c = 3.0, d = 4.0;
    test = (a == b) && (c == d);
    cout << "(a == b) && (c == d)" << test << endl;
    test = (a == b) || (c == d);
    cout << "(a == b) || (c == d)" << test << endl;
    // conditional operators
    a = 2; b = 3;
    cout << "(a = 2; b = 3)" << endl;
    (a < b) ? cout << a : cout << b;
    cout << endl;
    a = 3; b = 3;
    cout << "(a = 3; b = 3)" << endl;
    (a < b) ? cout << a : (a == b) ? cout << b : cout << "other";
    cout << endl;
    return 0;
}