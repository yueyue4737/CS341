// Copyright 2019 YueLiu liuyue2@bu.edu
// Object-oriented C++ Class
// Calculate the distance between two points 
// as well as the slope of line joining them
// reference1: slopeofstraightlineclass1.cpp
// reference2: firstclassenhanced.cpp
// Problem1: return statement inside the scope of its while loop --> Input
// Problem2: repeat cout the distance --> Output

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
// JM The following two statements are not necessary in this place.
// JM    cout << "Calculate distance and slope in a planar graph. Stop when hit CTRL-Z. Enter the coordinate of two points: " << endl;
// JM    cin >> x1 >> y1 >> x2 >> y2;
// Test for invalid input
// If the user ends of input, the program terminate
// JM    if (cin.eof()) {
// JM        cout << "User ends. Porgram Terminates." << endl;
// JM    }
    while (!cin.eof()) {
// If the user enters invalid data, 
// the program bypass the invalid and recover to accept next input
		cout << "Calculate distance and slope in a planar graph. Stop when hit CTRL-Z. Enter the coordinate of two points: " << endl;
		cin >> x1 >> y1 >> x2 >> y2;
		if (!cin.eof() && !cin.good()) {
        cout << "Invalid Input. Try Again!" << endl;
		exit(1); //JM The program goes into an infinite loop without this exit statement here, and appropriate 
		         //JM recovery action is not taken using methods cin.clear and cin.ignore, which makes the program  
				 //JM go into an infinite loop. The call to the system exit procedure is a sloppy way out of the
				 //JM infinite loop. You should use the cin.clear and cin.ignore methods to clear the cin flags 
				 //JM and the cin buffer before progam attempts to do additional input.  If you do not use 
				 //JM these two methods from the cin class to clear the cin status bits and the cin buffer, the 
				 //JM program will attempt to read the bad data a successive time and so forth and thereby it 
				 //JM will go into an infinite loop.
        }
        // Else we calculate the distance and slope
        else if (!cin.eof() && cin.good()) {
                p.putX1(x1);
                p.putY1(y1);
                p.putX2(x2);
                p.putY2(y2);
                dist = p.distance();
                cout << "The distance between two points is: " << dist << endl;
// Elucidian Distance = square root(power (sum (two differences in x&y))
// Slope = delta difference y / delta difference x (x part cannot be 0) 
                        if (!cin.eof() && cin.good() && p.testDenominator() == false) {
                                cout << "The slope of the line joiing two points is undifined" << endl;
                        }
                        else if (!cin.eof() && cin.good() && p.testDenominator() == true) {
                                slp = p.slope();
                                cout << "The slope of the line joiing two points is: " << slp << endl;
                        }                   
        }    
    } 
	return 0;
}
