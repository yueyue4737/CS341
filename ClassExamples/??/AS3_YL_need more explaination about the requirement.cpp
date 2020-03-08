#include <iostream>
#include <string>
using namespace std;

// definition of Stack class

class Stack
{
public:
	Stack() {}
	~Stack() {}
	Stack* Push(Stack*, string);
	string Peek(Stack*);
	Stack* Pop(Stack*);
	void DisplayStack(Stack*); // For runtime diagnosic purpose only
private:
	string Data;
	Stack* Next;
};

// full method definitions for class Stack, except for Stack() and ~Stack()

Stack* Stack::Push(Stack* Ptr, string A)
{
	Stack* temp;
	temp = new Stack;
	if (temp != NULL)
		{ temp->Next = Ptr;
		  temp->Data = A;
		}
	return temp;
}

string Stack::Peek(Stack* Ptr)
{	string myData = "No Data";
	if (Ptr != NULL) 
		myData = Ptr->Data;
	return myData;
}

Stack* Stack::Pop(Stack* Ptr)
{	Stack* temp = Ptr;
if (Ptr != NULL) {
	temp = Ptr->Next;
	delete Ptr;
	}
	return temp;
}

void Stack::DisplayStack(Stack* Ptr)
{
	Stack* temp = Ptr;
	if (temp == NULL)
		{
		cout << "Stack Is Empty." << endl;
		}
	else {
		cout << "Data in Stack is: " << endl;
		while (temp != NULL)
		{
			cout << temp->Data << endl;
			temp = temp->Next;
		}
		cout << endl;
	}
}

int main()
{
	bool toexit = false;
	char Option;
	string userData;
	Stack myStack;
	Stack* StackPtr = NULL;
	cout << "Welcome to the Stack program." << endl;
	while (!cin.eof() && toexit == false)
	{		cout << "Press 1 to Push, 2 to Pop, 3 to Peek, 4 to Display, ^z to end" << endl;
		cout << "Option: ";
		cin >> Option;
		if (!cin.eof()&& cin.good() && toexit == false) {
		switch (Option)
		{
		case '1':
			cout << "Enter Your Data: ";
			cin >> userData;
			if (!cin.eof())
			{
				StackPtr = myStack.Push(StackPtr, userData);
				if (StackPtr != NULL) {
					cout << "User's Data " << userData << " is Pushed into the stack!" << endl;
					}
				else {
					cout << "Stack full - unable to enter more data" << endl;
					toexit = true;
				}
			}
			else
				toexit = true;
			break;
		case '2':
			StackPtr = myStack.Pop(StackPtr);
			if (StackPtr == NULL)
			{
				cout << "Stack Is Empty!" << endl;
			}
			break;
		case '3':
			userData = myStack.Peek(StackPtr);
			if (userData == "")
			{
				cout << "Stack Is Empty!" << endl;
			}
			else
			{
				cout << "Peeked Element is: " << userData << endl;
			}
			break;
		case '4':
			myStack.DisplayStack(StackPtr);
			break;
		case '0':
			cout << "\n\n***Thank You For Using My Stack ***\n\n";
			return 0;
		default:
			cout << "Invalid Selection. Try Again..." << endl;
		}
	}// If not program termination, we need a Stack destructor here 
		//  to return any undeleted heap to the memory manager.
	}
return 0;
}