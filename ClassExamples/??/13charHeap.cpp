// Copyright 2019 YueLiu liuyue2@bu.edu
// Heap Memory: Character String

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char *ptr;
    //char strcpy
    if (ptr = new (char [strlen ("Hello World!") + 1])) {
        strcpy (ptr, "Hello World!");
        cout << ptr << endl;
        delete[] ptr; // give back the assignment of heap memory
        ptr = NULL; // set pointer to NULL to remove access to the heap memory
    }
    else
        cout << "Insufficient Dynamic Memory" << endl;    
    return 0;
}