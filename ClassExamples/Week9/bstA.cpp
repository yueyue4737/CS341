// Author: John Maslanka  copyright 2002, 2019
// Date:   23-Jul-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0
//
// C++ program to illustrate Binary Tree development and
// access using a Node class to develop and query individual 
// Nodes of the tree and a BT class to develop and query the
// entire tree. Each node is created only when it is needed 
// to contain a new character value entered by the user. 
// This example uses uses a Container class.
//
// Edit 10/21/2019 JM use inOrder traversal to display a tree.
// Replaces Jim Goddard's pretty print of a tree from M&S p506

#include <iostream>
#include <iomanip>  // for setw
#include <cstdlib>
#include <string>
using namespace std;

class Node {
private:
	string val; // current value in collating sequence
	Node* lh; // pointer to left-hand descendant Node
	Node* rh; // pointer to right-hand descendant Node

public:
	Node() { lh = rh = NULL; val = ""; }  // Node () {}
	void putVal(string v) { val = v; }
	string getVal() { return val; }
	void putLH(Node* x) { lh = x; }
	Node* getLH() { return lh; }
	void putRH(Node* x) { rh = x; }
	Node* getRH() { return rh; }
	void write(Node* n, int depth);
};

void Node::write(Node* n, int depth) { // Diagnostic to display a node of a Binary 
	cout << depth;
	cout << setw(4 * depth) << " "; // indentation
	cout << val << "       in Node at " << (int)n;
}

class BT {  // Container class - does most of the work
private:
	int count;
	Node* root;
	Node* tree;
	int depth;
private:
	Node* addNode(Node*, string);
	Node* findInsertion(Node*, string);
	void inOrder(Node*, int);
	void locate(Node*, string);
public:
	BT();
	void addRootNode(string);
	void inOrderTraverse();
	int  getCount() { return count; }
	void locateRoot(string);
};

BT::BT() { root = tree = NULL; count = 0; }    // BT::BT () {}
void BT::addRootNode(string v)
{
	if (root == NULL)
	{
		root = tree = addNode(tree, v);
		//	 cout << "ptr to root " << root << endl;
	}
	else
	{
		tree = root;
		tree = findInsertion(tree, v);
	}
}
Node* BT::findInsertion(Node* tree, string v)
{
	string x;
	x = tree->getVal();
	if (v == x)
		cout << "Not allowed to insert duplicate. Node is already in tree." << endl;
	else if (v < x)
		if (tree->getLH() != NULL)
		{
			tree = findInsertion(tree->getLH(), v);
			return tree;
		}
		else
		{
			Node* temp = NULL;
			temp = addNode(temp, v);
			tree->putLH(temp);
		}
	else // if ( v > x )
		if (tree->getRH() != NULL)
		{
			tree = findInsertion(tree->getRH(), v);
			return tree;
		}
		else
		{
			Node* temp = NULL;
			temp = addNode(temp, v);
			tree->putRH(temp);
		}
	return tree;
}
Node* BT::addNode(Node* x, string v)
{
	if (x = new Node)
	{
		x->putVal(v);
		++count;
		//  cout << count << " " << x << " " << x->getVal () << endl;
		x->putLH(NULL);
		x->putRH(NULL);
	}
	return x;
}
void BT::locateRoot(string v) {
	if (root == NULL)
		cout << "Tree is empty" << endl;
	else
		locate(root, v);
}
void BT::locate(Node* y, string v) {  // Bugfix mentioned by Dan Glade
	string x;
	x = y->getVal();
	if (v == x)
	{
		cout << "Value " << v << " is in Node at address " << (int)y << endl;
	}
	else if (v < x)
		if (y->getLH() != NULL)
			locate(y->getLH(), v);
		else
			cout << "Value not in tree" << endl;
	else // if ( v > x )
		if (y->getRH() != NULL)
			locate(y->getRH(), v);
		else
			cout << "Value not in tree" << endl;
}
void BT::inOrderTraverse()
{ //tree = root;
	cout << endl;
	inOrder(root, -1);
}
void BT::inOrder(Node* n, int depth)
{
	++depth;
	if (n != NULL) {
		inOrder(n->getLH(), depth);
		n->write(n, depth);
		cout << endl;
		inOrder(n->getRH(), depth);
	}
	return;
}

int main() {
	string x;
	char op = ' ';
	BT TREE;
	// Create inorder Binary treee
	cout << "To create your Binary tree, use the menu below." << endl;
	while (!cin.eof() && op != 'E' && op != 'e')  // build a binary tree in this while loop
	{//cout << "Enter your operation:  Add a Node, show Tree, Exit: ";
		cout << "Enter your operation using the capital letter shown in your selection." << endl;
		cout << "Add a node, display Tree, Find node, Exit: ";
		cin >> op;
		if (!cin.eof() && op != 'E' && op != 'e')
			switch (op)
			{
			case 'A': case 'a':
			{ cout << "Enter your string: ";
			cin >> x;
			if (!cin.eof())
				TREE.addRootNode(x);
			break;
			}
			case 'T': case 't':
			{if (TREE.getCount())
			{
				cout << endl << "Display Tree:" << endl;
				TREE.inOrderTraverse();
				cout << endl;
			}
			break;
			}
			case 'F': case 'f':
			{cout << "Enter your string: ";
				cin >> x;
				if (!cin.eof())
				TREE.locateRoot(x);
			}
			case 'E': case 'e':
			{ break;
			}
			default:
			{ cout << "Invalid operation. Try again!" << endl;
			break;
			}
		}
	}
	//    system("PAUSE");
	return EXIT_SUCCESS;
}
