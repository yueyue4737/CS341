// a class with more than one object

#include <iostream>
#include <cmath>
using namespace std;

class OrderedPair {
public:
	OrderedPair();
	OrderedPair(double, double);
	OrderedPair(OrderedPair&);
	~OrderedPair();
	void putX(double);
	double getX();
	void putY(double);
	double getY();
	double distanceToOtherPoint(const OrderedPair&);
	double slopeOfLine(const OrderedPair&);
private:
	double x;
	double y;
};

OrderedPair::OrderedPair() { x = y = 0; }
OrderedPair::OrderedPair(double a, double b)
{
	x = a; y = b;
}
OrderedPair::OrderedPair(OrderedPair& Z)
{
	x = Z.x; y = Z.y;
}
OrderedPair::~OrderedPair() { };

void	OrderedPair::putX(double a) { x = a; }
double	OrderedPair::getX() { return x; }
void	OrderedPair::putY(double a) { y = a; }
double	OrderedPair::getY() { return y; }


double	OrderedPair::distanceToOtherPoint(const OrderedPair& Z)
{
	return sqrt(pow(x - Z.x, 2) + pow(y - Z.y, 2));
}
double	OrderedPair::slopeOfLine(const OrderedPair& Z)
{
	return ((y - Z.y) / (x - Z.x));
}

int main() {
	OrderedPair A;
	OrderedPair B(1, 2);
	OrderedPair C(B);

	C.putX(3);
	C.putY(4);

	cout << "For Ordered Pair A, x = " << A.getX()
		<< " y = " << A.getY() << endl;
	cout << "For Ordered Pair B, x = " << B.getX()
		<< " y = " << B.getY() << endl;
	cout << "For Ordered Pair C, x = " << C.getX()
		<< " y = " << C.getY() << endl;

	cout << "Distance between Ordered Pairs A and C is "
		<< A.distanceToOtherPoint(C) << endl;
	cout << "Slope of Line BC is " << B.slopeOfLine(C) << endl;

	return 0;
}
