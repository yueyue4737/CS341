

#include <iostream>   
using namespace std;  

class Arithmetic {
public: 
	Arithmetic() { ct = 0; sum = 0; }   
	void   addToSum (double number) { sum += number; }
	double getSum() { return sum; }
	void   incrementCount() { ct++; }
	int    getCount() { return ct; }
	double calculateAverage() { return sum / ct; }
	bool   testCount()
	{
		if (ct > 0)
			return true;
		  else 
				return false; }
private:  
	int ct;
	double sum;
};

int main()  
{
	double nr;
	Arithmetic A;   
  
	cout << "Enter your numbers one at a time, and hit the Enter button after each." << endl;
	while (!cin.eof() && cin.good()) 
	{
		cout << "Enter a number >";
		cin >> nr;
		if (!cin.eof() && cin.good()) {
			A.addToSum(nr);
			A.incrementCount();
		}
	}
	if (!cin.eof() && !cin.good()) { 
		cout << "Invalid data entered." << endl;
		}	
	cout << "Sum = " << A.getSum() << " and Count = " << A.getCount() << endl;
	if (A.testCount()) 
		cout << "Average = " << A.calculateAverage() << endl;
	return 0;
}
