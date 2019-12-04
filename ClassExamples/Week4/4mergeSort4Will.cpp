// Author: John Maslanka
// Date: 30-May-2000
// Installation: Home PC with MS Visual C++ V 6.0
//
// C++ program to accept a number of integer numbers
// from the user's primary, to use rand() the random number 
// generator to create a list of numbers, to sort 
// the array in ascending sequence, and to display the 
// numbers in sorted order.
// This program illustrates a function call with 
// parameters passed by dereferencing using the address constant
//  of the declared array.
// The actual parameters are passed as addresses of array
// elements. 
// Timing procedures initially provided by William Baldumas
//  were reworked by me to work with my sorting algorithms. 9/27/2016

#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>

using timeframe = std::chrono::microseconds;
//using namespace std;

void mergesort(int[], int);
void merge(int[], int, int);

int main ()
{// initial work
 int i, j, x[100000];
 int n, t1, t2;
 std::cout << "Enter the number of integers to be generated, " << std::endl;
 std::cout << "Number must be 2 or greater: ";
 std::cin >> n;
 if (!std::cin.eof() && std::cin.good() && n > 1)
	{
	 std::srand (0);
	 for (i = 0; i < n; ++i)	// Edit 1/22/2016
		x[i] = std::rand();
	 if (n < 101) {
		 std::cout << "Initial array is ";
		 for (i = 0; i < n; ++i)
			 std::cout << x[i] << " ";
		 std::cout << std::endl; // end of initial work
		}
	 // beginning of main work
	 auto seed{ std::chrono::system_clock::now().time_since_epoch().count() };
	 //std::default_random_engine gen(seed);
	 //timeframe totalTime = (timeframe)0;
	 auto begin = std::chrono::high_resolution_clock::now();
	 mergesort(x, n);
	 auto end = std::chrono::high_resolution_clock::now();
	 timeframe totalTime = std::chrono::duration_cast<timeframe>(end - begin);
	 // end of main work
	 // final work
	 std::cout << "Run Time for Merge Sort: " << totalTime.count() << " microseconds\n";
	 if (n < 101) {
		 std::cout << "Final array is ";
		 for (i = 0; i < n; ++i)
			 std::cout << " " << x[i];
		 std::cout << std::endl;
		}
	 } 
 else	// Edit 1/22/2016
	{
	 std::cout << "Invalid input" << std::endl;   // Edit 1/22/2016
	}
std::cout << "Program terminating" << std::endl;
return EXIT_SUCCESS;
 // end of final work
}

void mergesort(int data[], int n)
{
	int n1, n2;
	if (n > 1)
	{
		n1 = n / 2;
		n2 = n - n1;
		mergesort(data, n1);
		mergesort((data + n1), n2);
		merge(data, n1, n2);
	}
}
void merge(int data[], int n1, int n2)
{
	int *temp;
	int copied = 0;
	int copied1 = 0;
	int copied2 = 0;
	int i;
	temp = new int[n1 + n2];
	// if(temp != NULL) {
	while ((copied1 < n1) && (copied2 < n2))
	{
		if (data[copied1] < (data + n1)[copied2])
			temp[copied++] = data[copied1++];
		else
			temp[copied++] = (data + n1)[copied2++];
	}
	while (copied1 < n1)
		temp[copied++] = data[copied1++];
	while (copied2 < n2)
		temp[copied++] = (data + n1)[copied2++];
	for (i = 0; i < n1 + n2; ++i)
		data[i] = temp[i];
	delete[] temp;
	// }
}
