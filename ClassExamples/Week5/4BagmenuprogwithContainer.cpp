

#include <string>
#include <iostream>
using namespace std;

class Node {
public:
	Node () {}
	Node* putNode (Node*, string);
	string getNodeData ();
	Node* getNextPointer ();
	void putNextPointer (Node*);
private:
	string st;
	Node* nextPtr;
};

Node* Node::getNextPointer (){
	return nextPtr;
}
void Node::putNextPointer (Node* x){
	this->nextPtr = x;
}
Node* Node::putNode (Node* x, string s) {
	Node* temp = NULL;
	if (temp = new Node()) {
		temp->nextPtr = x;
		temp->st = s;
	}
	return temp;
}
string Node::getNodeData() {
	return st;
}

class BagList {  
public:
	BagList ();
	void putANode (string);
	void getList ();
	Node* findNode (string);
	void  deleteNode (string);
private:
	Node* ListPointer;
};


BagList::BagList () 
	{ListPointer = NULL;}
void BagList::putANode (string udata) {
	bool x = false;
	Node* temp1;
	Node A;
	temp1 = A.putNode (ListPointer, udata);
	if (temp1 != NULL)
		ListPointer = temp1;
}
void BagList::getList() { 
	Node* temp;
	for (temp = ListPointer; temp != NULL;
									temp = temp->getNextPointer()) 
		cout << " User Data " << temp->getNodeData () << endl;
}
Node* BagList::findNode (string udata){
	Node* temp;
	for (temp = ListPointer; temp != NULL && temp->getNodeData () != udata; 
		                    temp = temp->getNextPointer());
	return temp;
}
void BagList::deleteNode (string udata) {  
	Node* delPtr = findNode (udata); 
	if (delPtr != NULL) {
		if (ListPointer == delPtr)
			ListPointer = delPtr->getNextPointer();
		else { 	Node* previousPtr; 
			Node* temp = ListPointer; 
			for (previousPtr = NULL; temp != delPtr; 
				previousPtr = temp, temp = temp->getNextPointer());
			previousPtr->putNextPointer(delPtr->getNextPointer());
		}
		delete delPtr;
		delPtr = NULL; 
		cout << "Node deleted: " << udata << endl;
	}
	else
		cout << "Node not found: " << udata << endl;
}

int main () {
    BagList A; 
    string udata;
	bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
	cout << "Enter your function: Add, Delete, Exit, Find, List: ";
	cin >> sel;
	if (!cin.eof()) {
	    switch (sel) {		
		case 'A': case 'a': {
		    cout << "Enter a string of characters or control-z to end ";
		    cin >> udata;
		    if (!cin.eof())
				A.putANode(udata); 
		    break;
		}
		case 'D': case 'd': { 
			cout << "Please Enter User Data value to delete: ";
			cin >> udata;
			if (!cin.eof()) 
				A.deleteNode (udata);
			break;
			}
		case 'E': case 'e': {
			cont = false;
			break;
			}
		case 'F': case 'f': {
			cout << "Please Enter User Data value to find: ";
			cin >> udata;
			if (!cin.eof()) 
				if (A.findNode(udata))
					cout << "Node " << udata << " found" << endl;
				else
					cout << "Node " << udata << " not found" << endl; 
			break;
			}
		case 'L': case 'l': {
			cout << "List of nodes" << endl;
			A.getList();
			cout << endl;
			break;
			}
		default: {
			cout << "Invalid function entered." << endl;
			break;
			 }
		   }
	    }
	}
//	system ("PAUSE");
	return 0;
}
