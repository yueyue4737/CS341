// Author: John Maslanka
// Date: 30-May-2000
// Installation: Home PC with MS Visual C++ V 6.0
//
// C++ program to accept a number of integer numbers
// from the user's primary, to use rand() the random number 
// generator to create a list of numbers,to sort 
// the array in ascending sequence, and to display the 
// numbers in sorted order.
// This program illustrates a function call with 
// parameters passed by dereferencing using the * operator.
// The actual parameters are passed as addresses of array
// elements. 
// Edit 1/22/2016 -- JM Provide testing of individual input 
// numeric data values

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

void swap (int*, int *);

int main ()
{
 int i, j, x[20];
 int n;
 cout << "Enter the number of integers to be generated: ";

 cin >> n;
 if (!cin.eof() && cin.good())
	{srand (0);
	 for (i = 0; !cin.eof() && cin.good() && i < n; ++i)
		  x[i] = rand ();

	 if (!cin.eof() && cin.good()) {  		
		cout << "Initial array is ";
			for (i = 0; i < n; ++i)
				cout << x[i] << " ";
			cout << endl; 


			for (i = 0; i < n-1; ++i)  
				for (j = 0; j < n-1-i; ++j) 
					if (x[j] > x[j + 1])
					{	//bubble swap procedure
						int temp = x[j];
						x[j] = x[j+1];
						x[j+1] = temp;
					}

			cout << "Final array is ";
			for (i = 0; i < n; ++i)
				 cout << " " << x[i];
			cout << endl;
			}
		else	
			 cout << "Invalid input" << endl;  
		}
 cout << "Program terminating" << endl;
 system("PAUSE");
 return EXIT_SUCCESS;
 // end of final work
}
