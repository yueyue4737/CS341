// Copyright 2019 YueLiu liuyue2@bu.edu
// Factorial: recursion
#include <cstdlib>
#include <iostream>
using namespace std;

int factorial(int); // global area: for defining funtion & c++ classes
int main() {
    int nr;
    cout << "Enter a positive integer to find its factorial, or EOF to terminate " << endl;
    cin >> nr;
    if (!cin.eof() && cin.good() && nr > 0)
    {
        cout << "Factorial is: " << factorial(nr) << endl;
    }
        else
    cout << "Invalid Input. Try Again!" << endl;    
    return EXIT_SUCCESS;
}
int factorial(int x) {
    // subsets should be disjoint
    int y = 1; // base case
    if (x > 1) y = factorial(x - 1); // statement
    return x*y; // return value
}