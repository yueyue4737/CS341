

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

void SelectionSort(int[], int);

int main ()
{
 int i, j, x[100000];
 int n, t1, t2;
 std::cout << "Enter the number of integers to be generated, " << std::endl;
 std::cout << "Number must be 2 or greater: ";
 std::cin >> n;
 if (!std::cin.eof() && std::cin.good() && n > 1)
	{
	 std::srand (0);
	 for (i = 0; i < n; ++i)
		x[i] = std::rand();
	 if (n < 101) {
		 std::cout << "Initial array is ";
		 for (i = 0; i < n; ++i)
			 std::cout << x[i] << " ";
		 std::cout << std::endl;
		}

	 auto seed{ std::chrono::system_clock::now().time_since_epoch().count() };
	 auto begin = std::chrono::high_resolution_clock::now();
	 SelectionSort(x, n);
	 auto end = std::chrono::high_resolution_clock::now();
	 timeframe totalTime = std::chrono::duration_cast<timeframe>(end - begin);
	 std::cout << "Run Time for Selection Sort: " << totalTime.count() << " microseconds\n";
	 if (n < 101) {
		 std::cout << "Final array is ";
		 for (i = 0; i < n; ++i)
			 std::cout << " " << x[i];
		 std::cout << std::endl;
		}
	 } 
 else
	{
	 std::cout << "Invalid input" << std::endl; 
	}
std::cout << "Program terminating" << std::endl;
return EXIT_SUCCESS;
}

void SelectionSort(int arr[], int size)
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

		int temp = arr[i];
		arr[i] = arr[smallestIndex];
		arr[smallestIndex] = temp;
	} 
} 
