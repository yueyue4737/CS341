
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
 cout << "Bubble Sort Demo Program with user input" << endl;
 cout << "  Enter no more than 20 integers" << endl;
 cout << "Enter the number of integers to be entered: ";
 cin >> n;
 if (!cin.eof() && cin.good() && n > 1 && n < 21)
 {
	 for (i = 0; !cin.eof() && cin.good() && i < n; ++i)
		 cin >> x[i];
	 if (!cin.eof() && cin.good()) {
		 cout << "Initial array is ";
		 for (i = 0; i < n; ++i)
			 cout << x[i] << " ";
		 cout << endl; // end of initial work

		 for (i = 0; i < n - 1; ++i)  
			 for (j = 0; j < n - 1 - i; ++j)  
				 if (x[j] > x[j + 1])
					 swap(x + j, x + j + 1);

		 cout << "Final array is ";
		 for (i = 0; i < n; ++i)
			 cout << " " << x[i];
		 cout << endl;
	 }

	 {
		 cout << "Invalid input" << endl;  
		 cin.clear();
		 cin.ignore(INT_MAX, '\n');
	 }
 }
 else
	 cout << "Invalid input count";
 cout << "Program terminating" << endl;
 system("PAUSE");
 return 0;

}
void swap ( int* a, int* b)
{ int temp = *a;
  *a = *b;
  *b = temp;
}
