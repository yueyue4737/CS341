// Author: John Maslanka   BinarySearchTree3E.cpp
// Date:   23-Jul-2002/ 4-Apr-2017
// Installation: Home PC with MicroSoft Visual C++ V15
//
// C++ program to illustrate Binary Tree development and
// access using a Node class to develop and query individual 
// Nodes of the tree and a BST class to develop and query the
// entire tree. Each node is created only when it is needed 
// to contain a new character value entered by the user. 
// This example uses the Data Structure technique known as 
// Aggegation.  Also, it uses a Container class for the
// Binary Search Tree.
// 
// Edit 10/27/2014   Code for AVL tree balancing. Original
// code from Jeremy Wright.
//
// Edit 11/10/2014   Code to display a binary tree after 
// Main & Savitch p 506, from Jimmy Goddard.
// Edit 11/18/2019 Replace Jimmy Goddard Tree display with
// a Tree based on In-Order Traversal

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
	void   writeTreeNode(Node* n, int depth);
	void   write(Node* n, int depth);
};

void Node::writeTreeNode(Node* n, int depth) { // Display a node of a binary tree
	cout << (int)n << "   " << depth << "   ";
	cout << setw(4 * depth) << " " << val << endl; // Successive indentation
 }

void Node::write(Node* n, int depth) { // Display a node of a Binary Tree
	cout << val << "\t in Node at location " << (int)n << endl;
}

// binarysearchtree.h
class BST { // Container for Binary Search Tree
private:
  int count;
  Node* root;
  Node* tree;
private:
  Node* addNode (Node*, string);
  Node* findInsertion (Node* tree, string v);
  void inOrder (Node*, int);
  void locate (Node*, string);
  void rotateRight (Node*);
  void rotateLeft (Node*);
  void postInsertionBalance (Node*);
  void treeDisplay(Node*, int);
public:
  BST ();
  void addNodeWrapper (string);
  void inOrderTraverse ();
  void preOrderTraverse ();
  void postOrderTraverse ();
  int  getCount () { return count; }
  void locateRoot (string);
  int  balanceFactor(Node*);
  int  subTreeHeight(Node*);
  void treeDisplayWrapper();
};
// binarytree.cpp
BST::BST () { // Default Constructor
	root = tree = NULL; count = 0; 
} 

void BST::addNodeWrapper (string v)
{ if (root == NULL)
    {
	  root = tree = addNode (tree, v);
    }
  else
    { tree = root;
      tree = findInsertion (tree, v);
    }
}

Node* BST::findInsertion (Node* tree, string v)
{ string x;
  x = tree -> getVal();
  //cout << count << " compare " << v << " and " << x << endl;
  if ( v < x ) //look to left of current node
    if( tree -> getLH () !=NULL )
      { tree = findInsertion (tree -> getLH(), v);
	return tree;		// *** from Paul Pollack 11/13/13 *** prevent 
						// a new node from being added twice
      }
    else
      { Node* temp = NULL;
		temp = addNode (temp, v);
		tree ->putLH(temp);
		temp ->setParent(tree); //added functionality for parents
		postInsertionBalance(temp); //balance the tree
      }
  else if ( v > x )  // look to right of current node
    if (tree -> getRH () !=NULL )
      { tree = findInsertion (tree -> getRH(), v);
		return tree;  // from Paul Pollack 11/13/13 same as above 
      }
    else
      { Node* temp = NULL;
		temp = addNode (temp, v);
		tree ->putRH(temp);
		temp ->setParent(tree);  //added functionality for parents
		postInsertionBalance(temp); //balance the tree
      }
  else
	  cout << "Node " << x << " found -- already in Binary Tree." << endl;
  return tree;
}
Node* BST::addNode (Node* x, string v)
{ if (x = new Node)
    { x->putVal (v);
      ++count;
      x->putLH(NULL);
      x->putRH(NULL); 
      x->setParent(NULL);
    }
  return x;
}
void BST::locateRoot (string v) {
  if ( root == NULL )
    cout << "Tree is empty" << endl;
  else
    locate ( root, v );
}
void BST::locate (Node* y, string v) {  // Bug mentioned by Dan Glade
  string x;
  x = y -> getVal ();
  if ( v == x )
    { cout << "Value " << v << " is in Node at reference " << (int)y << endl;
	  cout << " Left Child ref " << (int)y->getLH() << "    Right Child ref " << (int)y->getRH();
	  cout << "    Parent ref " << (int)y->getParent() << endl;
    }
  else if ( v < x )
    if ( y -> getLH() != NULL )
      locate (y-> getLH(), v);
    else
      cout << "Value not in tree" << endl;
  else // if ( v > x )
    if ( y -> getRH() != NULL )
      locate ( y-> getRH(), v );
    else
      cout << "Value not in tree" << endl;
}
void BST::inOrderTraverse ()
{ cout << endl;
  inOrder (root, -1); 
}
void BST::inOrder (Node* n, int depth)
{ if (n != NULL) {
	++depth;
    inOrder (n->getLH(), depth);
	n->write(n, depth);
    inOrder (n->getRH(), depth);
  }
  return;
}
void BST::treeDisplayWrapper() {
  treeDisplay(root, -1);
}

void BST::treeDisplay(Node* n, int depth) {
	if (n != NULL) {
		++depth;
		treeDisplay(n->getLH(), depth);
		n->writeTreeNode(n, depth);
		treeDisplay(n->getRH(), depth);
	}
	return;
}
// This BST procedure uses rotations to do AVL-balance whenever a Node is added.  
// In order to do this in all levels of the tree, it calculates a balance 
// factor, and uses this to determine when to rotate Nodes of the tree.  The 
// rotations are made so as to preserve the navigation of the tree. 
// The AVL balancing technique allows us to circumvent the problem of balancing 
// the input (more about this later in the course), when we can rebalance the 
// tree after each node is added. However, the AVL technique consumes much 
// overhead. For ease of programming, nodes now keep track of their parents to 
// facilitate the rotating procedure. 
// Note that the AVL technique does not handle the problem of deleting a Node
// from a BST.
void BST::postInsertionBalance(Node* n)  //Run after every insertion to 
										 // balance the tree.  Any imbalances can be dealt with by looking at 
										 // the parent line to root of the new Node as mentioned above.
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
  if(n == NULL)
    {
      return -1;
    }
  if(n->getLH() == NULL)
    {
      if(n->getRH() == NULL)
		{
		  return 0;
		}
      else
		{
		  subHeightR = subTreeHeight(n->getRH())+1;
		  return subHeightR;
		}
    }
  else if(n->getRH() == NULL)
    {
      subHeightL = subTreeHeight(n->getLH())+1;
      return subHeightL;
    }
  else
    {
      subHeightL = subTreeHeight(n->getLH()) + 1;
      subHeightR = subTreeHeight(n->getRH()) + 1;
      if(subHeightL > subHeightR)
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
{ cout << "Rotate Right" << endl;
  Node* pivot = subRoot->getLH();   //new root of this subtree is the left child
  Node* parentRoot = subRoot->getParent();  //store parent of subtree
  subRoot->putLH(pivot->getRH());  //the root takes the right child of the pivot 
									// to preserve BST structure
  if(subRoot->getRH() != NULL)
    {
      subRoot->getRH()->setParent(subRoot);  //make sure child knows its parent
    }
  pivot->putRH(subRoot); //the root becomes the right child of the pivot
  subRoot->setParent(pivot);
  if(subRoot == root)
    {
      root = pivot;
      pivot->setParent(NULL);
    }
  else  //connect subtree to its parent
    {
      if(parentRoot->getLH() == subRoot)
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
void BST::rotateLeft(Node* subRoot) //Rotates tree left as Rotate_Right
{ cout << "Rotate Left" << endl;
  Node* pivot = subRoot->getRH();   
  Node* parentRoot = subRoot->getParent();
  subRoot->putRH(pivot->getLH());
  if(subRoot->getRH() != NULL)
    {
      subRoot->getRH()->setParent(subRoot);
    }
  pivot->putLH(subRoot);
  subRoot->setParent(pivot);
  if(subRoot == root) // Need to test if entire tree is balanced!!!
    {
      root = pivot;
      pivot->setParent(NULL);
    }
  else
    {
      if(parentRoot->getLH() == subRoot)
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
int main () {
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
    { cout << "Enter your operation: ";
      cin >> op;
      if (!cin.eof () && op != 'E' && op != 'e')
	switch (op)
	  {
	  case 'A': case 'a':
	    { cout << "Enter your string: ";
	      cin >> x;
	      if (!cin.eof())
				TREE.addNodeWrapper (x);
	      break;
	    }
	  case 'S': case 's':
	    {if ( TREE.getCount ())
			{ cout << endl << "In-OrderTree Traversal" << endl;
			  TREE.inOrderTraverse ();
			}
		else
			cout << endl << "Tree is empty. No entries found.";
		cout << endl;
	    break;
	    }
	  case 'D': case 'd':
	    { cout << endl << "Enter User value of Node to Display: ";
	      cin >> x;
	      if (!cin.eof())
			 { TREE.locateRoot ( x );
			   cout << endl;
		     }
	      break;
	    }
	  case 'T': case 't':
		{if ( TREE.getCount ())
			{ cout << endl << "Display Tree:" << endl;
			  TREE.treeDisplayWrapper ();
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
