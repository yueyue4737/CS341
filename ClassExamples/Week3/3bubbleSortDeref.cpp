

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
			cout << endl; // end of initial work

		
			for (i = 0; i < n-1; ++i)  
				for (j = 0; j < n-1-i; ++j) 
					if (x[j] > x[j + 1])
						swap(x + j, x + j + 1);


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

}
void swap ( int* a, int* b)
{ int temp = *a;
  *a = *b;
  *b = temp;
}
