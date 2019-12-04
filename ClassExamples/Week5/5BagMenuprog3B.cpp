

#include <iostream>
using namespace std;
#include <cstdlib>

class Node {
public:
	Node ();  
	Node* putNode (Node*, double);  
	Node* findNode (Node*, double);  
	void  getList (Node*);
	Node* deleteNode (Node*, double);
private:
	double nr;     
	Node* nextPtr; 
};

Node::Node () {}

Node* Node::putNode (Node* NodePtr, double udata) {
	Node* temp = NULL;
	temp = new Node();  
	if (temp) {	
		temp->nextPtr = NodePtr;	
		temp->nr = udata;	
	}
	return temp;  
}
Node* Node::findNode (Node* NodePtr, double udata){
	Node *temp;
	for (temp = NodePtr; temp != NULL && temp->nr != udata; 
		                    temp = temp->nextPtr);
	return temp;
}
void Node::getList(Node* NodePtr) {
	Node* temp;
	for (temp = NodePtr; temp != NULL; temp = temp->nextPtr) 
		cout << " User Data " << temp->nr << endl;
}
Node* Node::deleteNode (Node* NodePtr, double udata) {
	Node* delPtr = findNode (NodePtr, udata); 
	if (delPtr == NULL) {
		cout << "Node " << udata << " not found." << endl;
	}
	else
	{  
		if (delPtr == NodePtr) { 
			NodePtr = delPtr->nextPtr; 
		}
		else { 
			Node* prevPtr; 
			Node* temp = NodePtr; 
			for (prevPtr = NULL; temp != delPtr; 
				prevPtr = temp, temp = temp->nextPtr) ;
			prevPtr->nextPtr = delPtr->nextPtr; 
		}
		delete delPtr; 
		cout << "Node " << udata << " deleted." << endl;
		delPtr = NULL; 
	}
	return NodePtr;  
}

int main () { 

	Node* listHdr = NULL;  
    double udata;
	bool cont = true;
    char sel;
    while (!cin.eof()&&cin.good()&&cont == true) { 
	  cout << "Enter your function: Add, Exit, Find, List, Delete: ";
	  cin >> sel;
	  if (!cin.eof()) { 
		Node A;
	    switch (sel) {	
		case 'A': case 'a': { 
		    cout << "Enter a double-precision number or control-z to end ";
		    cin >> udata;
		    if (!cin.eof() && cin.good()){ 
				Node* temp1;  
				temp1 = A.putNode(listHdr, udata);  
				if (temp1 != NULL)		 
					listHdr = temp1;	
				else  
					cout << "No more Heap memory. No more Data can be added to list." << endl;
				} 
			else
				if (!cin.eof())
					cout << "Invalid data entered" << endl;
		    break;
		    } 
		case 'E': case 'e': {
			cont = false;
			break;
			} 
		case 'F': case 'f': {
			cout << "Please Enter User Data value to find: ";
			cin >> udata;
			if (!cin.eof() && cin.good()) 
				if (A.findNode(listHdr, udata)) 
					cout << "Node " << udata << " found" << endl;
				else
					cout << "Node " << udata << " not found" << endl; 
			break;
			}
		case 'L': case 'l': {
			if (listHdr != NULL){
				cout << "List of nodes" << endl; 
				A.getList(listHdr);
				}
			else
				cout << "List is Empty";
			cout << endl;
			break;
			}
		case 'D': case 'd': {
		    cout << "Enter a double-precision number or control-z to end ";
		    cin >> udata;
		    if (!cin.eof() && cin.good()){ 
				listHdr = A.deleteNode(listHdr, udata);
				}
			cout << endl;
			break;
			}
		default: {
			cout << "Invalid selection entered." << endl;
			break;
			 }
		   }
	    }
	}
	system ("PAUSE");
	return 0;
}
