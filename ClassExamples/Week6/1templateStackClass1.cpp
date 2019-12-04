

#include <iostream>
#include <string>
using namespace std;


template <class T> 
class Stack        
{
public:
	Stack();
	Stack(int = 10);
	~Stack() { delete[] stackPtr; }
	bool push(const T&);
	bool pop(T&);  
	int isEmpty()const { return top == -1; }
	int isFull() const { return top == size - 1; }
private:
	int size;
	int top;
	T* stackPtr;
};

template <class T>
Stack<T>::Stack()
{
	size = 10;
	top = -1;
	stackPtr = new T[10];
	if (!stackPtr) {
		cout << " Sufficient Heap not found." << endl;
		exit(1);
	}
}
template <class T>
Stack<T>::Stack(int s)
{
	size = s > 0 && s < 1000 ? s : 10;
	top = -1;  // initialize stack
	stackPtr = new T[size];
	if (!stackPtr) {
		cout << " Sufficient Heap not found." << endl;
		exit(1);
	}

}
 
template <class T>
bool Stack<T>::push(const T& item)
{
	bool gb = false;  
	if (!isFull())
	{
		stackPtr[++top] = item;
		gb = true; 
	}
	return gb;
}

template <class T>
bool Stack<T>::pop(T& popValue)
{
	bool gb = false;    
	if (!isEmpty())
	{
		popValue = stackPtr[top--];
		gb = true; 
	}
	return gb;
}

int main()
{
	cout << "Please enter your number of double precision numbers ";
	int d;
	cin >> d;
	if (!cin.eof() && cin.good() && d > 0)
	{
		Stack<double> DblStack(d);
		double f = 1.1;
		cout << "Pushing elements onto double stack " << endl;
		while (DblStack.push(f))
		{
			cout << f << ' ';
			f += 1.1;
		}
		cout << endl << "Stack Full." << endl
			<< endl << "Popping elements from double stack " << endl;
		while (DblStack.pop(f))
			cout << f << ' ';
		cout << endl << "Stack now Empty" << endl;
		cout << endl;
	}

	cout << "Please enter your number of integer numbers ";
	cin >> d;
	if (!cin.eof() && cin.good() && d > 0) {
		Stack<int> IntStack(d);
		cout << "Pushing elements onto int stack " << endl;
		int i = 1;
		while (IntStack.push(i))
		{
			cout << i << ' ';
			i += 1;
		}
		cout << endl << "Stack Full" << endl
			<< endl << "Popping elements from int stack" << endl;
		while (IntStack.pop(i)) {
			cout << i << ' ';
		}
		cout << endl << "Stack now Empty" << endl;
	}
	return 0;
}
