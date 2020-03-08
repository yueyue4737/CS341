// Copyright 2019 YL liuyue2@bu.edu
// cin.getline member function: enter a character string

#include <iostream>
using namespace std;

int main()
{
    int idx;
    char buffer[256];
    cout << "Enter a character string: ";
    cin.getline(buffer, 256);
    if (!cin.eof()) {
            cout << "Beginning at the memory location " << (int) &buffer << endl;
            for (idx = 0; buffer[idx] != '\0'; idx++)
                    cout << " buffer [" << idx << "] contains " << buffer[idx] << " ASCII internal value"
                            << (int) buffer[idx] << endl;
                    idx++;
                    cout << " buffer [" << idx << "] = " << buffer[idx] << " ASCII internal value"
                            << (int)buffer[idx] << endl;
                    cout << "Buffer contains " << buffer << endl;
    }
    return 0;
}