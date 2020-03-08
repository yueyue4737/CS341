// Copyright 2019 YueLiu liuyue2@bu.edu
// Heap Memory: using character string

#include <iostream>
#include <string>
using namespace std;

int main() {
    int* ptr;
    if (ptr = new (int[5])) {
        cout << (int)ptr << endl;
        int j;
        for (j = 0; j < 5; j++)
            *(ptr + j) = 2 * j; // save the value passed back by the new operator
        for (j = 0; j < 5; j++)
            cout << *(ptr + j) << " ";
        cout << endl;
        delete[] ptr;
        ptr = NULL;
        // Test the value passed by is not equal to NULL
        if (ptr != NULL) {
            for (j = 0; j < 5; j++)
                cout << *(ptr + j) << " ";
        }
        cout << endl;
    }
    else 
        cout << "Insufficient dynamic memory" << endl;
    return 0;
}