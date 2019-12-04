// Author: John Maslanka; timing procedure originally provided by William Baldumas, Sep 2016
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

void BubbleSort(int[], int);

int main ()
{// Part 1 -- initial work
 int i, j, x[100000];
 int n, t1, t2;
 std::cout << "Enter the number of integers to be generated, " << std::endl;
 std::cout << "Number must be 2 or greater: ";
 std::cin >> n;
 if (!std::cin.eof() && std::cin.good() && n > 1)
	{
	 std::srand (0);	// use call to srand ONLY ONCE during a program run.
	 for (i = 0; i < n; ++i)	// Edit 1/22/2016
		x[i] = std::rand();
	 if (n < 101) {
		 std::cout << "Initial array is ";
		 for (i = 0; i < n; ++i)
			 std::cout << x[i] << " ";
		 std::cout << std::endl; // end of initial work
		}
	 // Part 2 -- beginning of main work
	 auto seed{ std::chrono::system_clock::now().time_since_epoch().count() };
	 //std::default_random_engine gen(seed);
	 //timeframe totalTime = (timeframe)0;
	 auto begin = std::chrono::high_resolution_clock::now();
	 BubbleSort(x, n);
	 auto end = std::chrono::high_resolution_clock::now();
	 timeframe totalTime = std::chrono::duration_cast<timeframe>(end - begin);
	 // end of main work
	 // Part 3 -- final work
	 std::cout << "Run Time for Bubble Sort: " << totalTime.count() << " microseconds\n";
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

void BubbleSort(int x[], int n) {
	int i, j;
	for (i = 0; i < n - 1; ++i)  // counts the number of passes through the array
		for (j = 0; j < n - 1 - i; ++j)  // counts the number of comparisons as we make one pass through the array 
		{
			if (x[j] > x[j + 1])
			{
				int temp = x[j];  // The Bubble
				x[j] = x[j + 1];    //
				x[j + 1] = temp;    //
			}
		}

}
