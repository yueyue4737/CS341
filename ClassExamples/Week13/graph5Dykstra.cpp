// Author: John Maslanka    Graph5Dykstra.cpp  copyright 2019
// Date: 27-Dec-2002,  4/11/2017  8/30/2019
// Installation: Home PC with MicroSoft Visual C++ V6.0
// Elementary Illustration of a Directed Graph adapted from 
// Figures 15.2 and 15.3 in Main and Savitch, but terminal 
// input is available. The program asks the user how many
// vertices to enter. If the user enters 100, 
// the vertex numbers are from 0 to 99. The user then enters the
// edges by giving the start vertex followed by the end vertex
// up to the product of the number of vertices times the 
// number of vertices less 1, or you can terminate edge input  
// with control-z. Note: An edge looping back to its first 
// vertex is disallowed in this code. So, if we wish to make 
// the starting point the same as the ending point, a separate 
// nude number has to be assigned for each activity.  This will
// cause the graph to function as a pass-thru graph.
//
// From Thomas Dattilo  11-April-2017
//  Sets up a two-dimensional Adjacency Matrix which is
//  produced at run-time so that it uses only the array size
//  that is required. Also, it uses multiple layered occurrences 
//  of the two dimensional array matrix to avoid the ambiguity 
//  of the question of when to terminate the traversal of the 
//  array when only one copy of the matrix is present in the 
//  program's address space.
//
// 8/30/2019 JM This version of the program allows the user to 
//  calculate the total distance through the graph of any given 
//  traversal. In addition to entering the positions of the 
//  beginning and termination of a segment, the program also 
//  requires the user to enter the length of each segment. 
//  Subsequently, the program calculates the traversal of the 
//  path from one node to another for any pair of nodes which 
//  were entered by the user. 
//  Note: This version of the program is named after Edsgar W.  
//  Dykstra, the famous mid-twentieth-century mathematician and 
//  computer scientist who developed the initial trip-loading 
//  algorithm which produced the most advantageous order in which 
//  to place customer orders for delivery, from last to first, in 
//  the van of a delivery truck.
//
//  This program does not cover Breadth-First Traversals.

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

class Edge {
private:
	int arraySize;	   // From Thomas Dattilo
	bool **edgeArray;  // declare the reference to the reference to the
					   // individual nodes of the Adjacency matrix.
	double **edgeLength;  // lengths of edges, which are parallel to nodes 
						  // of Adjacency matrix
public:
	Edge(int size) { // Constructor to create square matrix in the Heap 
					 // See first tree_level method below.
		arraySize = size;
		edgeArray = new bool*[size]; // Declare "From" dimension of matrix
		edgeLength = new double*[size];  // declare parallel first dimension of array of lengths
		for (int x = 0; x < size; x++) {
			edgeArray[x] = new bool[size]; // Declare "To" dimension of matrix
			edgeLength[x] = new double[size];  // JM  Declare second dimension of array of lengths
		}
		for (int y = 0; y < size; y++) {  // Fill all bits of matrix with 
			for (int z = 0; z < size; z++) {  // false bits
				edgeArray[y][z] = false;
				edgeLength[y][z] = 0.0;  // Initialize nodes of array of lengths to 0.0
			}
		}
	}

	Edge(const Edge& original) {  // Use this constructor to produce an additional
								  // parallel copy of the matrixes as needed.
								  // (See second tree_level method below.)
		this->arraySize = original.arraySize;
		this->edgeArray = new bool*[arraySize];
		this->edgeLength = new double*[arraySize];  // JM
		for (int x = 0; x < arraySize; x++) {
			this->edgeArray[x] = new bool[arraySize];
			this->edgeLength[x] = new double[arraySize];   // JM
		}
		for (int y = 0; y < arraySize; y++) {
			for (int z = 0; z<arraySize; z++) {
				this->edgeArray[y][z] = original.edgeArray[y][z];
				this->edgeLength[y][z] = original.edgeLength[y][z];  // JM
			}
		}
	}

	bool getEdge(int from, int to) const {
		return edgeArray[from][to];
	}
	double getLength(int from, int to) const {  // JM
		return edgeLength[from][to];
	}
	void setEdge(int from, int to) {
		edgeArray[from][to] = true;
	}
	void setLength(int from, int to, double length) {  // JM
		edgeLength[from][to] = length;
	}
	void resetEdge(int from, int to) {
		edgeLength[from][to] = false;
	}
};

class Graph {
private:
	Edge    *edge;
	int     count_of_vertices;
public:
	Graph() { count_of_vertices = 0; }
	int size() { return count_of_vertices; }
	void add_vertexes( int);
	void add_edge(int source, int target, double length);  // JM add length
	bool get_edge(int a, int b) { return edge->getEdge(a, b); }
	double get_length(int a, int b) { return edge->getLength(a, b); }  // JM
	bool is_edge(int source, int target);
	void tree_level(int);
	void tree_level(int, int, Edge&, double);    // JM add length parameeter
};

void Graph::add_vertexes( int nr ) {
	count_of_vertices = nr;
	edge = new Edge(count_of_vertices);
}

void Graph::add_edge(int source, int target, double length) {
	edge->setEdge(source, target);
	edge->setLength(source, target, length);  // JM
}

bool Graph::is_edge(int source, int target) {
	return edge->getEdge(source, target);
}

void Graph::tree_level(int x)  // wrapper method for Level builder
{ 
	int j, i;
	int level = 1;
	Edge temp(*edge);  // Thomas D - declare temp reference to new array
	for (j = 0; j < size(); ++j)
	{
		double cumLength = 0.0;    // JM add length
		if (edge->getEdge(x, j))
		{
			for (i = 1; i < level; cout << "   ", ++i);
			cumLength += edge->getLength(x, j);   // JM add length
			cout << "  (" << x << ", " << j << ") current distance = " << cumLength << endl;  // JM add length
			temp.resetEdge(x, j); // Thomas D - reset state of edge to false
			if (x != j)			  // Thomas D - test current from pos x vs. from pos j
				tree_level(j, level, temp, cumLength); // Thomas D -call recursive level tester // JM add length
		}
	}
}

void Graph::tree_level(int x, int level, Edge &original, double cumLength) // call to recursive level tester
{  // Note - third and fourth parameters are the only formal difference to this version of the method // JM add length
	int j, i;
	++level;
	
	double tempLength = cumLength;     // JM add tempLength variable
	Edge temp(original);  // TD create parallel matrix object
	for (j = 0; j < size(); ++j)
	{
		if (original.getEdge(x, j))
		{
			for (i = 1; i < level; cout << "   ", ++i);
			tempLength += edge->getLength(x, j);   // JM accumulate distance from beginning position
			// cout << " i = " << i << "  level " << level << " level length = " << edge->getLength(x, j - 1) << endl;  // JM for testing
			if (edge->getLength(x, j - 1) != 0.0)  // JM test if predecessor array entry not == 0
				tempLength -= edge->getLength(x, j - 1);  // JM yes, subtract that length from the accumulated length
			cout << "  (" << x << ", " << j << ") current distance = " << tempLength << endl;  // JM display length
			temp.resetEdge(x, j);
			if (x != j) {
				tree_level(j, level, temp, tempLength);  // JM   proceed to create next level of parallel array
			}
		}
	}
}
int main() {
	Graph G;
	int i, j, nr, x;
	double length;   // JM
	cout << "Enter number of vertices (1 < nr) ";
	cin >> nr;
	if (cin.eof() || !cin.good() || nr < 2)
	{
		cout << "Invalid input for number of vertices. "
			<< "Program terminating." << endl;
		exit(1);
	}
	G.add_vertexes(nr);
	cout << "Number of vertices is " << G.size() << endl << endl;
	cout << " Beginning and Terminating vertexes must be between 0 and "
		<< (nr - 1) << " inclusive" << endl;
	cout << "Beginning and terminating vertexes must not be "
		<< "the same for an edge in this graph." << endl;
	cout << " and the length of an edge must be greater than 0." << endl;
	cout << "Enter EOF at keyboard to view displays." << endl;
	for (x = 0; x < nr*(nr - 1) && !cin.eof();)
	{
		cout << "Enter the two bounding vertexes and the length of an edge: ";
		cin >> i >> j >> length;
		if (!cin.eof())
		{
			if (!cin.good() || i >= nr || j >= nr || i < 0 || j < 0 || i == j || !(length > 0))  // JM test constraints
				{
				cout << "Invalid input for an edge, try again." << endl;  // JM
				cin.clear();  // JM  Reset cin bits
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // JM  Clear remainder of input buffer
				}
			else
				{
				G.add_edge(i, j, length); // JM add the node and its length
				++x;
				}
		}
	}
	cout << endl;
	// JM initial display of vertexes and lengths of edges.
	cout << "Directed List of Nearest Neighbor Vertexes for each Vertex"
		<< endl;
	for (i = 0; i < G.size(); ++i)
	{
		cout << "For Vertex " << i << "     ";
		for (j = 0; j < G.size(); ++j)
			if (G.is_edge(i, j))
				cout << "   " << j << "  length is " << G.get_length(i, j);
		cout << endl;
	}
	cout << endl;
	system("PAUSE");
	//  JM  code to do call to make depth-first traversals
	for (i = 0; i < G.size(); ++i)
	{
		cout << "Depth-First Traversals of Trees on Graph with total distances of trips, "
			<< "starting with Vertex " << i << endl;
		G.tree_level(i);  // JM call to make one depth-first traversal 
	}
	system("PAUSE");
	return 0;
}
