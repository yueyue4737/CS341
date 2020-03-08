// Copyright YL liuyue2@bu.edu 10/19/2019
// Recover from bad input numeric data

#include <iostream>
using namespace std;

int main() {
    double sum = 0;
    int count = 0;
    double nr;
    cout << "Enter your numbers one at a time and hit Enter. Terminate with Ctrl-z" << endl;
    while (!cin.eof() && cin.good()) {
        cin >> nr;
        if (!cin.eof() && cin.good()) {
            sum += nr;
            count++;
        }
        else
            if (!cin.eof() && !cin.good()) {
                cout << "Invalid Input, Try Again!" << endl;
                cin.clear();
                cin.ignore(256, "\n");
            }
    }
    if (cin.eof() && count == 0)
        cout << "No valid data entered." << endl;
    else
        cout << "The sum is " << sum << endl
             << "The count is " << count << endl
             << "The average is " << sum / count << endl;
    return EXIT_SUCCESS;
}