

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

void mergesort(int[], int, int*, int*, int*);
void merge(int[], int, int, int*, int*, int*);

int main() {
	int i, n, x[100], level = 0, ct = 0, ctif = 0;
	int seed;
	cout << "Enter the number of integers to be entered: " << endl;
	cin >> n;

	if (!cin.eof() && cin.good()) {
		cout << "Enter each integer followed by hitting <enter> button. " << endl;
		for (i = 0; !cin.eof() && cin.good() && i < n; ++i)
		{
			cin >> x[i];
		}
		if (i < n) {
			if (!cin.eof())
				cout << "Insufficient valid entries.  Program terminating." << endl;
			exit(1);
		}
		cout << "Initial array is ";
		for (i = 0; i < n; ++i)
			cout << x[i] << " ";
		cout << endl;
		system("PAUSE");
		++level;
		cout << "Level is " << level << "  n = " << n << endl;

		mergesort(x, n, &level, &ct, &ctif);
		cout << endl << "Returned to level " << level << endl;
		cout << "Number of entries into merge method is " << ct << endl;
		cout << "Number of entries into key while header is " << ctif << endl;
		cout << "Sorted array -- at level " << level << "  is ";
		for (i = 0; i < n; ++i)
			cout << x[i] << " ";
		cout << endl;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
void mergesort(int data[], int n, int* lev, int* ct, int* ctif)
{
	int n1, n2;
	cout << "Entering mergesort method. ";
	if (n > 1)
	{
		n1 = n / 2;
		n2 = n - n1;
		cout << "n = " << n << " n1 = " << n1 << " n2 = " << n2 << endl;
		cout << endl << "Entering First call to mergesort method. ";
		++*lev;
		cout << "Level is " << *lev << "  n1 = " << n1 << endl;
		mergesort(data, n1, lev, ct, ctif);
		cout << "Returned to level " << *lev << endl;
		cout << endl << "Entering Second call to mergesort method. ";
		++*lev;
		cout << "Level is " << *lev << "  n2 = " << n2 << endl;
		mergesort((data + n1), n2, lev, ct, ctif);
		cout << "Returned to level " << *lev << endl;
		cout << endl << "Entering merge method. " << endl;
		++*lev;
		cout << "Level is " << *lev << "   n1 = " << n1 << "   n2 = " << n2 << endl;
		merge(data, n1, n2, lev, ct, ctif);
	}
	else   
		cout << "Initial singleton for level   " << *lev << " ---- " << data[0] << endl << endl;
	--*lev;
}
void merge(int data[], int n1, int n2, int* lev, int* ct, int* ctif)
{
	int *temp;
	int copied = 0;
	int copied1 = 0;
	int copied2 = 0;
	int i;
	++*ct; 
	cout << "Initial array for level   " << *lev << " ---- ";
	for (i = 0; i < n1 + n2; ++i)
		cout << data[i] << " ";
	cout << endl;
	temp = new int[n1 + n2];
	cout << "Entering key while loop" << endl;
	while ((copied1 < n1) && (copied2 < n2))
	{
		++*ctif;
		if (data[copied1] < (data + n1)[copied2]) {
			temp[copied++] = data[copied1++];
			cout << "Value " << temp[copied - 1] << " moved backwards in temp " << endl;
			for (i = 0; i < n1 + n2; ++i)
				cout << temp[i] << " ";
			cout << endl;
		}
		else {
			temp[copied++] = (data + n1)[copied2++]; 
			cout << "Value " << temp[copied - 1] << " moved forward in temp " << endl;
			for (i = 0; i < n1 + n2; ++i)
				cout << temp[i] << " ";
			cout << endl;
		}
	}
	cout << "Exiting key while loop" << endl;
	while (copied1 < n1) {
		temp[copied++] = data[copied1++];
		cout << "Fill-in value " << temp[copied - 1] << " from left-hand array segment " << endl;  
	}
	while (copied2 < n2) {
		++*ct;
		temp[copied++] = (data + n1)[copied2++];
		cout << "Fill-in value " << temp[copied - 1] << " from right-hand array segment " << endl; 
	}
	for (i = 0; i < n1 + n2; ++i)
		data[i] = temp[i];
	delete[] temp;
	cout << "Processed array for level " << *lev << " ---- ";
	for (i = 0; i < n1 + n2; ++i)
		cout << data[i] << " ";
	cout << endl;
	--*lev;
	cout << "Exiting merge method " << endl << endl;
}
