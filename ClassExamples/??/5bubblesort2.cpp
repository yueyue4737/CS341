// Copyright 2019 YueLiu liuyue2@bu.edu

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

void swapByRef(int&, int&);

int main()
{   // from the user's primary input
    // to create a list of numbers
    // and to display the numbers in sorted order
    // to sort the array in ascending sequence
    int i, j, x[20];
    int n;
    cout << "Enter the number of integers, 20 or less, to be entered: ";
    cin >> n;
    if (n > 20) {
        cout << "No more than twenty inputs are allowed! Terminating." << endl;
        exit(1);
    }
    if (!cin.eof() && cin.good()) {
        cout << "Please enter your " << n << " input numbers " << endl;
        for (i = 0; !cin.eof() && cin.good() && i < n; ++i)
            cin >> x[i];
    }
    if (!cin.eof() && cin.good()) {
        cout << "Initial Array is ";
        for (i = 0; i < n; ++i)
            cout << x[i] << " ";
        cout << endl;
        for (i = 0; i < n-1; ++i)
        {
            for (j = 0; j < n-1-i; ++j)
                if (x[j] > x[j+1])
                    swapByRef(x+j, x+j+1);
        }
        cout << endl;
        cout << "Final array is ";
        for (i = 0; i < n; ++i)
            cout << " " << x[i];
        cout << endl;
   }
    else 
        cout << "Invalid Input";
    cout << "Programing Terminating" << endl;
    return EXIT_SUCCESS;
}
void swapByRef(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}