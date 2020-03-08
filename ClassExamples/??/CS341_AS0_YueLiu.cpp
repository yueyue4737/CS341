// Copyright 2019 YueLiu liuyue2@bu.edu
// Calculate the distance between two points 
// as well as the slope of line joining them

# include <cmath>
# include <iostream>
using namespace std;

int main() {
// Prompt the user for input data: 
// two pairs of double-precision numbers
    double x1, y1, x2, y2;
    double x, y;
    double distance, slope;
    cout << "Calculate distance and slope in a planar graph" << flush;
    cout << "Stop when hit CTRL-Z" << flush;
    cout << "Enter the coordinate of two points: " << endl;
    cin >> x1 >> y1 >> x2 >> y2;
// Test for invalid input
// If the user ends of input, the program terminate
    if (cin.eof()) {
        cout << "User ends. Porgram Terminates." << endl;
    }
    while (!cin.eof()) {
// If the user enters invalid data, 
// the program bypass the invalid and recover to accept next input
        if (!cin.eof() && !cin.good()) {
        cout << "Invalid Input. Try Again!" << endl;
        }
        else 
// Else we calculate the distance and slope
                if (!cin.eof() && cin.good()) {      
// Elucidian Distance = square root(power (sum (two differences in x&y))
// Slope = delta difference y / delta difference x (x part cannot be 0) 
                            x = x1 - x2;
                            y = y1 - y2;
                            distance = sqrt(x * x + y * y);  
                            if (!cin.eof() && cin.good() && x == 0) {
                                cout << "The distance between two points is: " << distance << endl;
                                cout << "The slope of the line joiing two points is undifined" << endl;
                            }
                            else 
                                if (!cin.eof() && cin.good() && x != 0) {
                                    slope = y / x;
                                    cout << "The distance between two points is: " << distance << endl;
                                    cout << "The slope of the line joiing two points is: " << slope << endl;
                        }                   
    }       
    return 0;
}}


