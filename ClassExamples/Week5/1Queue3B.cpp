
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Node {  
	public: 
		Node () {}						
		Node* Admit (Node*, string);     
		Node* Serve (Node*);  
        string Peek ();          
		Node* getNextPointer ();  
	private: 
		string item;    
		Node* prior; 
		Node* next; 
};

Node* Node::Admit (Node* endPtr, string a)
	{Node* temp = NULL;
	 if (temp = new Node)
		{temp->item = a;
		 temp->next = NULL;
		 temp->prior = endPtr;
		 if ( endPtr != NULL)
			{ endPtr->next = temp;
			}
		}
	 else
		cout << "Dynamic memory exhausted" << endl;
	 return temp;
	}
Node* Node::Serve (Node* y)
	{Node* temp;
	 temp = y->next;
	 delete y;
	 if (temp != NULL)
		temp->prior = NULL;
	 return temp;
	}
string Node::Peek () 
	{return item;}
Node* Node::getNextPointer () 
	{ return next; } 

class Queue 
{
public:
	Queue ();
	bool admitEntrant (string);
	void serveSeniorEntrant ();
	string peekSeniorEntrant ();
private:
	Node* front;  
	Node* end; 
	bool  peekFlag; 
};

Queue::Queue () 
	{ front = end = NULL;
	  peekFlag = false; }
bool Queue::admitEntrant ( string x )
	{ bool admitSuccess = false;
	  Node A;
	  end = A.Admit (end, x);
	  if (end != NULL)
		{ if (front == NULL)
			front = end;
		  admitSuccess = true;
		}
	  return admitSuccess;
	}
string Queue::peekSeniorEntrant ()
	{ peekFlag = true;
	  string returnValue = "";
	  if (front != NULL)
		{ returnValue = front-> Peek ();
		}
	  else
	    { peekFlag = false;
		  cout << "Queue is empty." << endl;
		}
	  return returnValue;
	}
void  Queue::serveSeniorEntrant ()
	{ Node A;
	  if (peekFlag == true)
		if (front != NULL)
			{front = A.Serve (front);
	         if (front == NULL)  
				{				 
				 end = NULL;	
				}			
			}
		else
		  cout << "Queue is empty." << endl;
	  else
		  if (front == NULL)
			  cout << "Queue is empty." << endl;
		  else
			  cout << "Senior Queue Member has not been Peeked." << endl;
	  peekFlag = false;
	}


int main () {
Queue Q;
char resp = ' '; 
string cval;
cout << "Actions: Admit, Serve, Peek,"
     << " Help, Quit or ^Z" << endl;
while (!cin.eof() && resp != 'Q' && resp != 'q') {
  cout << "Enter action selection: ";
  cin >> resp;
  if (!cin.eof())
	{
     switch (resp) {
	   case 'A': case 'a': 
         	cout << "Enter name to enter into Node: ";
         	cin >> cval;
		if (!cin.eof()) 
		   { if ( Q.admitEntrant (cval) )
				 cout << "Added entrant " << cval << " to list." << endl;
			 else
				 cout << "Failed to add entrant " << cval << " to list." << endl;
           }
		 break;	
	   case 'S': case 's': 
		 Q.serveSeniorEntrant ();
		 break;
	   case 'P': case 'p': 
		 cout << Q.peekSeniorEntrant () << endl;
		 break;	
	   case 'h': case 'H':
		 cout << "Actions: Admit, Serve, Peek,"
		     << " Help, Quit or ^Z" << endl;
		 break;
	   case 'Q': case 'q':
		   break;
	   default:
		 cout << " Invalid Action. Try again." << endl;
	  }
	cin.clear();
	}
  }
  cout << "Thank you for using my Queue program." << endl;
  system("PAUSE");
  return EXIT_SUCCESS;
}
