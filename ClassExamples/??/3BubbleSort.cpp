// Copyright 2019 YueLiu liuyue2@bu.edu
// numeric data values
// bubble sort 
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int i, j, x[20];
    int n;
    cout << "Enter the number of integers, 20 or less, to be entered: ";
    cin >> n;
    if (!cin.eof() && cin.good())
             for (i = 0; !cin.eof() && cin.good() && i < n; ++i)
                     cin >> x[i];
    if (!cin.eof() && cin.good()) {
            // initial work
            cout << "Initial array is ";
            for (i = 0; i < n; ++i)
                    cout << x [i] << " ";
            cout << endl;
            // main work
            for (i = 0; i < n - 1; ++i) // numbers pass through the array
            {
                    for (j = 0; j < n - 1 - i; ++j) // number of comparisons
                            if (x[j] > x[j+1]) {
                                    int temp;
                                    temp = x[j];
                                    x[j] = x[j + 1];
                                    x[j + 1] = temp;
                            }
            }
            cout << endl;
            // final work
            cout << "Final array is: ";
            for (i = 0; i < n; ++i)
                    cout << " " << x[i];
            cout << endl;
    }
    else 
            cout << "Invalid input";
    cout << "Program terminating" << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}