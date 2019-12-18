// Singlelevel Inheritance  John Maslanka copyright 2009

#include <iostream>
using namespace std;

class Flatware {
protected:  // Designate Base class data members as protected 
		double length;	
		char*   material;
	public:
		Flatware ( ); 	// Default Constructor
	~Flatware ( );   // Destructor
		void     updateLength (double);
		double retrieveLength ( );
		void     updateMaterial (char*);
		char*   retrieveMaterial ( );
			};

class Fork : public Flatware {
private:
	int numberOfTynes;   // the number of the long thin projections from the base of the fork,
						 //  not including the handle, which is on the other end of the fork
public:
	Fork() { numberOfTynes = 4; }   // (Constructor) Four is the usual number
	void     updateNumberOfTynes(int);
	int		 retrieveNumberOfTynes();
};

class Spoon : public Flatware {
private:
	double capacity;   // in multiples of teaspoons
public:
	Spoon() { capacity = 1; }   // i.e. one teaspoon
	void     updateCapacity(double);
	double	 retrieveCapacity();
};


Flatware::Flatware ( )
	{ length = 0; 
	  material = new char [1];
	  *material = '\0';
	}
Flatware::~Flatware ( ) 	// Destructor
{ delete [ ] material; }
void      Flatware::updateLength (double a) 
	{ length = a; } 
double	  Flatware::retrieveLength ( ) 
	{ return length; }
void      Flatware::updateMaterial (char* a)
	{ char* temp;
	  if ( temp = new char [ strlen (a) +1 ])
		{strcpy ( temp, a );
		 delete[] material;
		 material = temp;
		}
	}
char*    Flatware::retrieveMaterial ( )
	{ return material; }

void	Fork::updateNumberOfTynes (int nr)
	{ numberOfTynes = nr; }
int		Fork::retrieveNumberOfTynes ()
	{ return numberOfTynes;}

void      Spoon::updateCapacity (double a) 
	{ capacity = a; }
double    Spoon::retrieveCapacity ()  
	{ return capacity; }

int main ( ) {
	Spoon sp; 
	sp.updateLength (6);
	sp.updateMaterial ("silver");
	sp.updateCapacity (3);  // teaspoons
	cout << "Spoon length is " << sp.retrieveLength() 
		 << ", material is " << sp.retrieveMaterial()
		 << ", capacity is " << sp.retrieveCapacity() 
		 << endl;
	Fork fork;
	fork.updateLength(4);
	fork.updateMaterial("plastic");
	//fork.updateNumberOfTynes(3);  // not updated, use original number
	cout << "Fork length is " << fork.retrieveLength()
		<< ", material is " << fork.retrieveMaterial()
		<< ", number of tynes is " << fork.retrieveNumberOfTynes()
		<< endl;
	return 0;
}
