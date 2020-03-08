// Copyright 2019 YueLiu liuyue2@bu.edu
// String Library

#include <string>
#include <iostream>
using namespace std;

int main() {
    char x = 'H', y = 'i', z = '!';
    cout << x << y << z << endl;
    string A = "Hello," ;
    cout << A << endl;
    string B = " Welcome to MET 231!";
    if (A == B)
            cout << " Sting A equals to string B." << endl;
    else 
            cout << " Sting A does not equal to string B." << endl;
    if (A < B)
            cout << " Sting A is smaller than string B." << endl;
    else
            cout << " Sting A is larger than string B." << endl;
    string C = "C,";
    cout << "String C contains " << C << endl;
    C.append(B);
    cout << " Sting C now contains " << C << endl;
    string C1 = "C1,";
    cout << " String C1 contains " << C1 << endl;
    C1 += B;
    cout << " String C1 now contains " << C1 << endl;
    string D;
    cout << "Please enter your own string > ";
    cin >> D;
    if (!cin.eof()) {
            cout << "String length = " << D.length() << endl;
            cout << A + D + "." + B << endl;
            cout << "String length = " << (A + D + "." + B).length() << endl;
    }
    return 0;
}