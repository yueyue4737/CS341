
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

	void mergesort (int[], int);
	void merge (int[], int, int);

int main () {  
int i, n, x[100];
cout << "enter the number of integers to be entered: ";
cin >> n;
if (!cin.eof() && cin.good() && (n >= 2 && n <= 100))  
	{cout << "Enter your integers, hitting <Enter> after each." << endl;
     for (i = 0; i < n; ++i)
		 cin >> x[i];
	if (!cin.eof() && cin.good())
	{

	 mergesort (x, n);

     cout << "Sorted array -- " ;
	 for (i = 0; i < n; ++i)
		 cout << x [i] << " ";
	 cout << endl;
	}
	}
 system("PAUSE");
 return EXIT_SUCCESS;
}	

void mergesort (int data[], int n)
{int n1, n2;
 if (n > 1)
   {n1 = n/2;
    n2 = n - n1;
    mergesort (data, n1);
    mergesort ((data + n1), n2);
    merge (data, n1, n2);
   }
}
void merge (int data[], int n1, int n2)
{int *temp;
 int copied = 0;
 int copied1 = 0;
 int copied2 = 0;
 int i;
 temp = new int[n1 + n2];
 // if(temp != NULL) {
 while ((copied1 < n1) && (copied2 < n2))
 {
   if (data[copied1] < (data + n1) [copied2])
        temp[copied++] = data[copied1++];
   else
        temp[copied++] = (data + n1)[copied2++];
 }
 while (copied1 < n1)
    temp[copied++] = data[copied1++];
 while (copied2 < n2)
    temp[copied++] = (data + n1)[copied2++];
 for (i = 0; i < n1+n2; ++i)
    data[i] = temp [i];
 delete [] temp;
 }
}
