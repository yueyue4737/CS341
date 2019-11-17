// Copyright 2019 YueLiu liuyue2@bu.edu
// Object-oriented C++ Class
// Calculate the distance between two points 
// as well as the slope of line joining them
// reference1: slopeofstraightlineclass1.cpp
// reference2: firstclassenhanced.cpp

# include <cmath>
# include <iostream>
using namespace std;

class Points {
public:
    Points();  // Default Constructor
    void putX1(double);
    void putY1(double);
    void putX2(double);
    void putY2(double);
    bool testDenominator();
    double distance();
    double slope();
private:
    double x1, y1, x2, y2;
    double dist, slp;
};
Points::Points()
{
    x1 = y1 = x2 = y2 = 0;
}
void Points::putX1(double x)
{
    x1 = x;
}
void Points::putY1(double x)
{
    y1 = x;
}
void Points::putX2(double x)
{
    x2 = x;
}
void Points::putY2(double x)
{
    y2 = x;
}
bool Points::testDenominator(){
    return ((x1 - x2) != 0) ? true : false;
}
double Points::distance(){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
}
double Points::slope(){
    return (y1 - y2) / (x1 - x2);
}
int main() {
    double x1, y1, x2, y2;
    double dist, slp; 
    Points p;
// Prompt the user for input data: 
// two pairs of double-precision numbers
    cout << "Calculate distance and slope in a planar graph. Stop when hit CTRL-Z. Enter the coordinate of two points: " << endl;
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
                        p.putX1(x1);
                        p.putY1(y1);
                        p.putX2(x2);
                        p.putY2(y2);
                        dist = p.distance();
// Elucidian Distance = square root(power (sum (two differences in x&y))
// Slope = delta difference y / delta difference x (x part cannot be 0) 
                            if (!cin.eof() && cin.good() && p.testDenominator() == false) {
                                cout << "The distance between two points is: " << dist << endl;
                                cout << "The slope of the line joiing two points is undifined" << endl;
                            }
                            else 
                                if (!cin.eof() && cin.good() && p.testDenominator() == true) {
                                    slp = p.slope();
                                    cout << "The distance between two points is: " << dist << endl;
                                    cout << "The slope of the line joiing two points is: " << slp << endl;
                        }                   
    }       
    return 0;
}}
