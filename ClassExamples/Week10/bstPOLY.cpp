// AVL Dynamic BTree Balancing listed below: is done at post-insertion for each
//   new Node.
// This BST procedure uses rotations to do AVL-balance whenever a Node is added.  
// In order to do this in all levels of the tree, it first calculates a balance 
// factor, and uses this to determine when to rotate Nodes of the tree.  The 
// rotations are made so as to preserve the efficiency of navigation thru the tree. 
// The AVL balancing technique allows us to circumvent the problem of statically
// balancing the input (more about this later in the course) when we can rebalance 
// the tree after each node is added. However, this procedure balances the tree
// from the point of view of depth and so it does not always produce a perfectly
// balanced tree. For ease of programming, nodes now keep track of their parents  
// to facilitate the rotation procedures. 
// Note that this AVL technique has not been tested to handle the problem of 
// deleting a Node from a Binary Search Tree (BST).
// see line 231
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
//#include "nodewithparent.h"
//#include "binarytree.h"
using namespace std;

// nodewithparent.h
class Node {
private:
	string val; // user input provides value in collating sequence
	Node* lh; // pointer to left-hand descendant Node
	Node* rh; // pointer to right-hand descendant Node
	Node* parent; //pointer to parent Node or NULL if root Node
public:
	Node() { lh = rh = parent = NULL; val = ""; }
	void   putVal(string v) { val = v; }
	string getVal() { return val; }
	void   putLH(Node* x) { lh = x; }
	Node*  getLH() { return lh; }
	void   putRH(Node* x) { rh = x; }
	Node*  getRH() { return rh; }
	void   setParent(Node* x) { parent = x; }
	Node*  getParent() { return parent; }
};

// binarytree.h
class BST { // Container for Binary Search Tree
private:
	int count;
	Node* root;
	Node* tree;
private:
	Node* addNode(Node*, string);
	Node* findInsertion(Node* tree, string v);
	void inOrder(Node*);
	void preOrder(Node*);
	void postOrder(Node*);
	void locate(Node*, string);
	void rotateRight(Node*);
	void rotateLeft(Node*);
	void postInsertionBalance(Node*);
	void treeDisplay(Node*, int);
public:
	BST();
	void addNodeWrapper(string);
	void inOrderTraverse();
	void preOrderTraverse(); // modify here
	void postOrderTraverse(); // modify here
	int  getCount() { return count; }
	void locateRoot(string);
	int  balanceFactor(Node*);
	int  subTreeHeight(Node*);
	void treeDisplayWrapper();
};
// binarytree.cpp
BST::BST() { // Default Constructor
	root = tree = NULL; count = 0;
}

void BST::addNodeWrapper(string v)
{
	if (root == NULL)
	{
		root = tree = addNode(tree, v);
	}
	else
	{
		tree = root;
		tree = findInsertion(tree, v);
	}
}

Node* BST::findInsertion(Node* tree, string v) // modify here
{
	string x;
	x = tree->getVal();
	// The following code up to the return statement provided by Patrick Abeya 11/2/2017
	// This code replaces the redundant code which existed in previous versions of this
	//  program. This code is similar to the code for Polymorphism.
	Node * (Node::*getMethod)(void) = nullptr;
	void (Node::*putMethod)(Node *) = nullptr;

	// Next 8 lines decide whether to go to left or right child of current node
	if (v <= x) { // user data value <= data value in current node
		getMethod = &Node::getLH;  // Assign reference to method getLH to getMethod
		putMethod = &Node::putLH;  // Assign reference to method putLH to putMethod
	}
	else {  // else user data value > data value in current node
		getMethod = &Node::getRH;  // Assign reference to method getRH to getMethod
		putMethod = &Node::putRH;  // Assign reference to method putRH to putMethod
	}

	// Now decide if there is a Left or Right child
	if ((tree->*getMethod)() != NULL) {  // Yes
		tree = findInsertion((tree->*getMethod)(), v); // Call findInsertion recursively
	}
	else // No 
	{
		Node* temp = NULL;		 // provide field for reference to new node
		temp = addNode(temp, v);   // Create new Node
		(tree->*putMethod)(temp);  //  and put its reference into the node of its parent
								   // Patrick Abeya's code ends here
		temp->setParent(tree);  //added functionality for parents; new child learns who its parent is
		postInsertionBalance(temp); //balance the tree
	}
	return tree;
}
Node* BST::addNode(Node* x, string v)
{
	if (x = new Node)
	{
		x->putVal(v);
		++count;
		x->putLH(NULL);
		x->putRH(NULL);
		x->setParent(NULL);
	}
	return x;
}
void BST::locateRoot(string v) {
	if (root == NULL)
		cout << "Tree is empty" << endl;
	else
		locate(root, v);
}
void BST::locate(Node* y, string v) {  // Parameter Bug mentioned by Dan Glade
	string x;
	x = y->getVal();
	if (v == x)
	{
		cout << "Value " << v << " is in Node at reference " << (int)y << endl;
		cout << " Left Child ref " << (int)y->getLH() << "    Right Child ref " << (int)y->getRH();
		cout << "    Parent ref " << (int)y->getParent() << endl;
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
void BST::inOrderTraverse()
{
	cout << endl;
	inOrder(root);
}
void BST::inOrder(Node* n)
{
	if (n != NULL) {
		inOrder(n->getLH());
		cout << n->getVal() << endl;
		inOrder(n->getRH());
	}
	return;
}
void BST::preOrderTraverse()
{
	cout << endl;
	preOrder(root);
}
void BST::preOrder(Node* n)
{
	if (n == NULL) return;
	cout << n->getVal() << endl;
	preOrder(n->getLH());
	preOrder(n->getRH());
}
void BST::postOrderTraverse()
{
	cout << endl;
	postOrder(root);
}
void BST::postOrder(Node* n)
{
	if (n != NULL) //return;
	{
		postOrder(n->getLH());
		postOrder(n->getRH());
		cout << n->getVal() << endl;
	}
}
void BST::treeDisplayWrapper() {
	treeDisplay(root, 0);
}

void BST::treeDisplay(Node* ref, int depth) {
	// Adapted from Main & Savitch, Data Structures and Oter Objects using C++,
	//	page 506 by Jimmy Goddard
	cout << setw(4 * depth) << ""; // indentation
	if (ref == NULL) {
		// reached a NULL reference in an interior node
		cout << "[NULL]" << endl;
	}
	else if (ref->getLH() == NULL && ref->getRH() == NULL) {
		// a leaf
		cout << "Value " << ref->getVal() << " at Ref " << (int)ref;
		cout << " [leaf]" << endl;
	}
	else {
		// a nonleaf - interior node
		if (depth == 0)
			cout << "       Root ";
		cout << "Value " << ref->getVal() << " at Ref " << (int)ref << endl;
		cout << "Left Child  " << depth + 1;
		treeDisplay(ref->getLH(), depth + 1);
		cout << "Right Child " << depth + 1;
		treeDisplay(ref->getRH(), depth + 1);
	}
}
void BST::postInsertionBalance(Node* n)  //Run after every insertion of a Node 
					// to balance the tree.  Any imbalances can be dealt with by looking at 
					// the parent line to the root of the new Node as described above.
{
	Node* p;
	if (balanceFactor(n) == 2)
	{
		p = n->getLH();
		if (balanceFactor(p) == -1)
		{
			rotateLeft(p);
		}
		rotateRight(n);
	}
	else if (balanceFactor(n) == -2)
	{
		p = n->getRH();
		if (balanceFactor(p) == 1)
		{
			rotateRight(p);
		}
		rotateLeft(n);
	}
	if (n != root) //run until we travel up to root
	{
		postInsertionBalance(n->getParent());
	}
}
int BST::balanceFactor(Node* n)
{
	return subTreeHeight(n->getLH()) - subTreeHeight(n->getRH());
}

int BST::subTreeHeight(Node* n) //tells the height of the larger subtree under this node.
{
	int subHeightL;
	int subHeightR;
	if (n == NULL)
	{
		return -1;
	}
	if (n->getLH() == NULL)
	{
		if (n->getRH() == NULL)
		{
			return 0;
		}
		else
		{
			subHeightR = subTreeHeight(n->getRH()) + 1;
			return subHeightR;
		}
	}
	else if (n->getRH() == NULL)
	{
		subHeightL = subTreeHeight(n->getLH()) + 1;
		return subHeightL;
	}
	else
	{
		subHeightL = subTreeHeight(n->getLH()) + 1;
		subHeightR = subTreeHeight(n->getRH()) + 1;
		if (subHeightL > subHeightR)
		{
			return subHeightL;
		}
		else
		{
			return subHeightR;
		}
	}
}
void BST::rotateRight(Node* subRoot)  //rotates a tree right, with subRoot as 
									  // its original root and pivot as the new root
{
	Node* pivot = subRoot->getLH();   //new root of this subtree is the left child
	Node* parentRoot = subRoot->getParent();  //store parent of subtree
	subRoot->putLH(pivot->getRH());  //the root takes the right child of the pivot 
									 // to preserve BST structure
	if (subRoot->getRH() != NULL)
	{
		subRoot->getRH()->setParent(subRoot);  //make sure child knows its parent
	}
	pivot->putRH(subRoot); //the root becomes the right child of the pivot
	subRoot->setParent(pivot);
	if (subRoot == root)
	{
		root = pivot;
		pivot->setParent(NULL);
	}
	else  //connect subtree to its parent
	{
		if (parentRoot->getLH() == subRoot)
		{
			parentRoot->putLH(pivot);
			pivot->setParent(parentRoot);
		}
		else
		{
			parentRoot->putRH(pivot);
			pivot->setParent(parentRoot);
		}
	}
}
void BST::rotateLeft(Node* subRoot) //Rotates Nodes left, symmetrical with Rotate_Right
{
	Node* pivot = subRoot->getRH();
	Node* parentRoot = subRoot->getParent();
	subRoot->putRH(pivot->getLH());
	if (subRoot->getRH() != NULL)
	{
		subRoot->getRH()->setParent(subRoot);
	}
	pivot->putLH(subRoot);
	subRoot->setParent(pivot);
	if (subRoot == root) // Need to test if entire tree is balanced!!!
	{
		root = pivot;
		pivot->setParent(NULL);
	}
	else
	{
		if (parentRoot->getLH() == subRoot)
		{
			parentRoot->putLH(pivot);
			pivot->setParent(parentRoot);
		}
		else
		{
			parentRoot->putRH(pivot);
			pivot->setParent(parentRoot);
		}
	}
}

// BinaryTreeApplication.cpp
int main() {
	string x;
	char op = ' ';
	char confirm = ' ';
	BST TREE;
	//Node* test;
	// Create inorder Binary treee
	cout << "To create your Binary tree, use the menu below." << endl << endl;
	cout << "Enter your operation using the capital letter shown in your selection." << endl;
	cout << "Add a node, Display a node, Show sorted list, display Tree, Help, Exit: " << endl;
	while (!cin.eof() && op != 'E' && op != 'e')  // build binary tree in this loop
	{
		cout << "Enter your operation: ";
		cin >> op;
		if (!cin.eof() && op != 'E' && op != 'e')
			switch (op)
			{
			case 'A': case 'a':
			{ cout << "Enter your string: ";
			cin >> x;
			if (!cin.eof())
				TREE.addNodeWrapper(x);
			break;
			}
			case 'S': case 's':
			{if (TREE.getCount())
			{
				cout << endl << "In-OrderTree Traversal" << endl;
				TREE.inOrderTraverse();
				//			  cout << "Pre-Order Tree Traversal" << endl << endl;
				//			  TREE.preOrderTraverse();
				//			  cout << "Post-Order Tree Traversal" << endl << endl;
				//			  TREE.postOrderTraverse();
			}
			break;
			}
			case 'D': case 'd':
			{ cout << endl << "Enter User value of Node to Display: ";
			cin >> x;
			if (!cin.eof())
			{
				TREE.locateRoot(x);
				cout << endl;
			}
			break;
			}
			case 'T': case 't':
			{if (TREE.getCount())
			{
				cout << endl << "Display Tree:" << endl;
				TREE.treeDisplayWrapper();
			}
			else
				cout << endl << "Tree is empty. No entries found.";
			cout << endl;
			break;
			}
			case 'H': case 'h':
			{ cout << "Enter your operation using the capital letter shown in your selection." << endl;
			cout << "Add a node, Display a node, Show sorted list, display Tree, Help, Exit" << endl;
			break;
			}
			case 'E': case 'e':
			{ break;
			}
			default:
			{ cout << "Invalid operation. Try again!" << endl;
			cout << "Operations are " << endl;
			cout << "Add a node, Display a node, Show sorted list, display Tree, Help, Exit" << endl;
			break;
			}
			}
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
