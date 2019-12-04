

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void displayStack(stack <string>);
int main()
{
	string userData;
	bool toexit = false;
	char Option;
	stack <string> s;
	cout << "Welcome to my STL Stack program." << endl;
	while (!cin.eof() && toexit == false)
	{	cout << "Press 1 to Push, 2 to Pop, 3 to Peek, 4 to Display stack, ^z to end" << endl;
		cout << "Option: ";
		cin >> Option;
		if (cin.eof()) {
			toexit = true;
			cout << "*** Thank You for using my STL Stack program ***" << endl;
		}
		else 
			if (!cin.eof() && cin.good() && toexit == false) {
			switch (Option)
				{
				case '1':
					cout << "Enter Your Data: ";
					cin >> userData;
					if (!cin.eof())
						s.push (userData);
					else
						toexit = true;
					break;
				case '2':
					if (!s.empty())
						s.pop();
					else
						cout << "Stack Is Empty!" << endl;
					break;
				case '3':
					if (!s.empty())
						cout << "Peeked element is " << s.top() << endl;
					else
						cout << "Stack Is Empty!" << endl;
					break;
				case '4':
					displayStack(s);
					break;
				default:
					cout << "Invalid Selection. Try Again..." << endl;
				}
			}
	}
return 0;
}

void displayStack(stack <string> stk)
{
	if (!stk.empty())
	{
		while (!stk.empty())
		{
			cout << stk.top() << endl;
			stk.pop();
		}
	}
	else
		cout << "Stack Is Empty!";
	cout << endl;
}
