// Copyright 2019 YueLiu liuyue2@bu.edu
// Textbook: chapter 10??

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    char filename[256]; // define an arrary of 256 character positions
    cout << "Please enter filename.extension to create: ";
    cin >> filename;
    if (cin.eof())
        exit(1);
    fstream outFile(filename, ios::out); //define the outFile object
    if (!outFile)
        cout << "Could not open file. Terminating." << endl;
    else
    {
        cout << "Enter student name [space char] grade and hit <Enter>"
            << endl << "Enter EOF to end input" << endl;
        char stname[10];
        int grade;
        while (!cin.eof() && cin.good()) {
            cout << "?";
            cin >> stname >> grade;
            if (!cin.eof() && cin.good())
                outFile << stname << ' ' << grade << endl;
        }
    }
    return EXIT_SUCCESS;
}