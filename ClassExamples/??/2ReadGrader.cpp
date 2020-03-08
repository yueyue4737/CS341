// Copyright 2019 YueLiu liuyue2@bu.edu
// st Read stream input file

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    string streamfilename;
    cout << "Enter the name of a file in your corrected folder: ";
    cin >> streamfilename;
    if (cin.eof())
            exit(1);
    fstream inFile(streamfilename, ios::in);
    if (!inFile)
            cout << "Could not open file. Terminating." << endl;
    else 
    {
        cout << "Student name and Grade" << endl;
        string stname;
        int grade, ct = 0, sum = 0;
        while (!inFile.eof())
        {
                inFile >> stname >> grade;
                if (!inFile.eof()) {
                    cout << stname << " " << grade << endl;
                    ++ct; sum += grade;
                }
        }
        if (ct)
        {
                cout << setw(7) << setprecision(4)
                        << "Count of students is: " << ct
                        << "    Total is: " << sum
                        << "    Average is " << (double)sum / ct
                        << endl;
        }
        else 
                cout << "File is empty." << endl;
    }
    return EXIT_SUCCESS;
}