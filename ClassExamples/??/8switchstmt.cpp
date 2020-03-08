// Copyright YL liuyue2@bu.edu 10/19/2019
// Switch Statement

#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    while (x++ < 5) {
        switch (x) {
            case 1:
                cout << "In case 1" << endl;
                break;
            case 2:
                cout << "In case 2" << endl;
                break;
            case 3:
                cout << "In case 3" << endl;
                break;
            case 4:
                cout << "In default case" << endl;
                break;
        }
    }
    return 0;
}