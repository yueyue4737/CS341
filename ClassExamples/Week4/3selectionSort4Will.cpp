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

void SelectionSort(int[], int);

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
	 SelectionSort(x, n);
	 auto end = std::chrono::high_resolution_clock::now();
	 timeframe totalTime = std::chrono::duration_cast<timeframe>(end - begin);
	 // end of main work
	 // final work
	 std::cout << "Run Time for Selection Sort: " << totalTime.count() << " microseconds\n";
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

void SelectionSort(int arr[], int size)
// Original code from William Baldoumas
{ 
	int smallest = 0;
	int smallestIndex = 0;

	for (int i = 0; i < size - 1; ++i) { 
		smallest = arr[i];
		smallestIndex = i;

		for (int j = i + 1; j < size; ++j) { 
			if (smallest > arr[j]) {
				smallest = arr[j];
				smallestIndex = j;
			}
		} 

		//MySwap(arr, i, smallestIndex);
		int temp = arr[i];
		arr[i] = arr[smallestIndex];
		arr[smallestIndex] = temp;
	} 
} 
//void MySwap(int32_t * arr, const uint32_t i, const uint32_t j)
// Original code from William Baldoumas
/*{
	int32_t temp{ arr[i] };
	arr[i] = arr[j];
	arr[j] = temp;
}
*/
