// Copyright YL liuyue2@bu.edu 10/19/2019

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    double sum = 0;
    int count = 0;
    double nr;
    count << "Enter your numbers one at a time and hit the enter" << endl;
    while (!cin.eof() && cin.good()) {
        sum += nr;
        count++;
        setw(10);
        setprecision(2);
        cout << "The sum is " << sum << endl
              << "The count is " << count << endl
              << "The average is " << sum / count << endl;
    }
    else 
        if (!cin.eof() && !cin.good()) {
            cout << "Invalid Input" << endl;
        }
    return EXIT_SUCCESS;
}