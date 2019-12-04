

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void swap (int*, int *);

int main ()
{int i, j, x[10];
 int n, t1, t2;
 cout << "Enter the number of integers to be generated: ";
 cin >> n;
 if (!cin.eof() && cin.good())
	{srand (0);
	 for (i = 0; i < n; ++i)
		 x[i] = rand ();
	 cout << "Initial array is ";
	 for (i = 0; i < n; ++i)
		 cout << x[i] << " ";
	 cout << endl;

     for (i = 0; i < n-1; ++i)
		 for (j = 0; j < n - 1 - i; ++j)
			if (x[j] > x[j + 1])
				swap(&x[j], &x[j + 1]);

	 cout << "Final array is ";
	 for (i = 0; i < n; ++i)
		 cout << " " << x[i];
	 cout << endl;
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
