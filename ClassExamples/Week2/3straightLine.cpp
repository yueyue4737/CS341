// a class with several objects

#include <iostream>
#include <cmath>
using namespace std;

class StraightLine {
public:
	StraightLine();
	StraightLine(double, double, double, double); // define 4 objects here
	~StraightLine() {}

	void putX1(double);
	double getX1();
	void putY1(double);
	double getY1();
	void putX2(double);
	double getX2();
	void putY2(double);
	double getY2();

	double distance();
	double slope();
private:
	double x1;
	double y1;
	double x2;
	double y2;
};

StraightLine::StraightLine() { x1 = y1 = x2 = y2 = 0; }
StraightLine::StraightLine(double a, double b, double c, double d)
{
	x1 = a; y1 = b; x2 = c, y2 = d;
}

void	StraightLine::putX1(double a) { x1 = a; }
double	StraightLine::getX1() { return x1; }
void	StraightLine::putY1(double a) { y1 = a; }
double	StraightLine::getY1() { return y1; }

void	StraightLine::putX2(double a) { x2 = a; }
double	StraightLine::getX2() { return x2; }
void	StraightLine::putY2(double a) { y2 = a; }
double	StraightLine::getY2() { return y2; }

double	StraightLine::distance()
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
double	StraightLine::slope()
{
	return ((y1 - y2) / (x1 - x2));
}

int main() {
	StraightLine A(1, 2, 3, 4);
	cout << "Distance between points is " << A.distance() << endl;
	cout << "Slope of Line is " << A.slope() << endl;
	A.putX1(5);
	A.putY2(7);
	cout << "Distance between points is " << A.distance() << endl;
	cout << "Slope of Line is " << A.slope() << endl;
	return 0;
}
