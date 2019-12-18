// MultiLevelInheritance.cpp  John Maslanka  copyright 7/12/2015


#include <iostream>
using namespace std;

class X {
protected: 
		double x;
public:
			X ( ) { x = 0; }
		void     updateX (double a) { x = a; }
		double   retrieveX ( ) { return x; }
	};  
class Y : public X {
protected: 
		double y;
public:
			Y ( ) { y = 0; }
		void     updateY (double a) { y = a; }
		double   retrieveY ( ) { return y; }
	};  
class Z : public Y {
		private: 
			double z;
		public:
			Z ( ) { z = 0; }
		void     updateZ (double a) { z = a; }
		double   retrieveZ ( ) { return z; }
	}; 

int main () {
	X C;
	Y B;
	Z A;
	cout << "Coordinate of point C is ( " 
		 << C.retrieveX() << " )" << endl;
	cout << "Coordinates of point B are ( " 
		 << B.retrieveX() << ", " 
		 << B.retrieveY() << " )" << endl;
	cout << "Coordinates of point A are ( " 
		 << A.retrieveX() << ", " 
		 << A.retrieveY() << ", " 
		 << A.retrieveZ() << " )" << endl;
	A.updateX(1);
	A.updateY(2);
	A.updateZ(3);
	B.updateX(4);
	B.updateY(5);
	C.updateX(6);
	cout << "Coordinate of point C is ( " 
		 << C.retrieveX() << " )" << endl;
	cout << "Coordinates of point B are ( " 
		 << B.retrieveX() << ", " 
		 << B.retrieveY() << " )" << endl;
	cout << "Coordinates of point A are ( " 
		 << A.retrieveX() << ", " 
		 << A.retrieveY() << ", " 
		 << A.retrieveZ() << " )" << endl;
	return 0;
}
