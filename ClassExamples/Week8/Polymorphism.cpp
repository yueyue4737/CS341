// Polymorphism  John Maslanka July 2015

#include <iostream>
using namespace std;

	class Figure {
	      public:
			virtual double Area ( ) = 0;    // Define ADT
	};
	class Rectangle : public Figure {
	      public:
			Rectangle ( double x, double y )
				{ side_a = x; side_b = y; }
			virtual double Area ( ) // define Area method of Rectangle class
			{ return side_a * side_b; }
	      private:
			double side_a;
			double side_b;
	};
	class Circle : public Figure {
	      public:
			Circle ( double x )
				{ radius = x; }
			virtual double Area ( )  // define Area method of Circle class
				{ return radius * radius * 3.14; }
	      private:
			double radius;
	};

	int main ( ) {
	Rectangle R (1,2);   // instantiate Rectangle and Circle objects
	Circle C (3); 
	Figure* ptr[2];        // define array of pointers to Figures
	ptr [0] = &R;           // assign references of objects to elements of 
				// pointer array
	ptr [1] = &C;
	for ( int i = 0; i < 2; ++i )   // manage the index of the “for” loop
	      if (i == 0 )    // invoke indexed Area method
		cout << "Area of Rectangle is " << ptr[i] -> Area() << endl;
	      else
		cout << "Area of Circle is " << ptr[i] -> Area() << endl;        
             return 0;
	}
