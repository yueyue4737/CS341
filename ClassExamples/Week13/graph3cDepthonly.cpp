// Author: John Maslanka    Graph5C-TD-DepthOnly.cpp
// Date: 27-Dec-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0
// Elementary Illustration of a Directed Graph adapted from 
// Figures 15.2 and 15.3 in Main and Savitch, but terminal 
// input is available. The program asks the user how many
// vertices to enter. If the user enters 100, 
// the vertex numbers are from 0 to 99. The user then enters the
// edges by giving the start vertex followed by the end vertex
// up to the product of the number of vertices times the 
// number of vertices less 1, or you can terminate edge input  
// with control-z. Note: FWIW an edge looping back to its first 
// vertex is disallowed in this code.
//
// From Thomas Dattilo  11-April-2017
//  Fix for same origin/return-point problem, which guarantees that
//  graph which that a depth-wise traverse of a route through a multi-
//  segment starts and ends at the same vertex will be completely 
//  shown.
//  Also, sets up a two-dimensional Adjacency Matrix which is
//  produced at run-time so that it uses only the array size
//  that is required.  
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
public:
	Edge(int size) { // Create square matrix in the Heap
		arraySize = size;
		edgeArray = new bool*[size]; // Declare "From" dimension of matrix
		for (int x = 0; x < size; x++) {
			edgeArray[x] = new bool[size]; // Declare "To" dimension of matrix
		}
		for (int y = 0; y < size; y++) {  // Fill all bits of matrix with 
			for (int z = 0; z < size; z++) {  // false bits
				edgeArray[y][z] = false;
			}
		}
	}
	Edge(const Edge& original) {  // Use this version to produce an 
								  // additional copy of the matrix as needed.
								  // (See second tree_level method below.)
		this->arraySize = original.arraySize;
		this->edgeArray = new bool*[arraySize];
		for (int x = 0; x < arraySize; x++) {
			this->edgeArray[x] = new bool[arraySize];
		}
		for (int y = 0; y < arraySize; y++) {
			for (int z = 0; z<arraySize; z++) {
				this->edgeArray[y][z] = original.edgeArray[y][z];
			}
		}
	}
	bool getEdge(int from, int to) const {
		return edgeArray[from][to];
	}
	void setEdge(int from, int to) {
		edgeArray[from][to] = true;
	}
	void resetEdge(int from, int to) {
		edgeArray[from][to] = false;
	}
};

class Graph {
private:
	Edge    *edge;
	int     count_of_vertices;
public:
	Graph() { count_of_vertices = 0; }
	int size() const { return count_of_vertices; }
	void add_vertexes(const int);
	void add_edge(int source, int target);
	bool get_edge(int a, int b) { return edge->getEdge(a, b); }
	bool is_edge(int source, int target) const;
	void tree_level(int, int); // prime the pump(initialize the process), for the dfs traversal
	void tree_level(int, int, const Edge&);
	Edge* getAnEdge();
};

Edge* Graph::getAnEdge() {
	return edge;
}

void Graph::add_vertexes(const int nr) {
	count_of_vertices = nr;
	edge = new Edge(count_of_vertices);
}

void Graph::add_edge(int source, int target) {
	edge->setEdge(source, target);
}

bool Graph::is_edge(int source, int target) const {
	return edge->getEdge(source, target);
}

void Graph::tree_level(int x, int level)  // Level tester wrapper
{
	int j, i;
	++level;
	Edge temp(*edge);  // Thomas D - declare temp reference to new array
	for (j = 0; j < size(); ++j)
	{
		if (edge->getEdge(x, j))
		{
			for (i = 1; i < level; cout << "   ", ++i);
			cout << "  (" << x << ", " << j << ")" << endl;
			temp.resetEdge(x, j); // Thomas D - reset usage of edge 
			if (x != j)			  // Thomas D - test current from pos x vs. from pos j
				tree_level(j, level, temp); // Thomas D -call recursive level tester 
		}
	}
}

void Graph::tree_level(int x, int level, const Edge &original) // call to recursive level tester
{  // Note - third parameter is the only formal difference to this version
	int j, i;
	++level;
	Edge temp(original);
	for (j = 0; j < size(); ++j)
	{
		if (original.getEdge(x, j))
		{
			for (i = 1; i < level; cout << "   ", ++i);
			cout << "  (" << x << ", " << j << ")" << endl;
			temp.resetEdge(x, j);
			if (x != j)
				tree_level(j, level, temp);
		}
	}
}
int main() {
	Graph G;
	int i, j, nr, x;
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
	cout << "Enter EOF at keyboard to view displays." << endl;
	for (x = 0; x < nr*(nr - 1) && !cin.eof();)
	{
		cout << "Enter the two bounding vertexes of an edge " << endl;
		cin >> i >> j;
		if (!cin.eof())
		{
			if (!cin.good() || i >= nr || j >= nr)
			{
				cout << "Invalid input for an edge. "
					<< "Program terminating." << endl;
				exit(1);
			}
			if (i == j)
				cout << "Beginning and terminating vertexes must not be "
				<< "the same for an edge in this graph." << endl;
			else
			{
				G.add_edge(i, j);
				++x;
			}
		}
	}
	cout << endl;
	cout << "Directed List of Nearest Neighbor Vertexes for each Vertex"
		<< endl;
	for (i = 0; i < G.size(); ++i)
	{
		cout << "For Vertex " << i << "     ";
		for (j = 0; j < G.size(); ++j)
			if (G.is_edge(i, j))
				cout << "   " << j;
		cout << endl;
	}
	cout << endl;
	system("PAUSE");
	for (i = 0; i < G.size(); ++i)
	{
		cout << "Depth-First Traversal of Trees on Graph "
			<< "starting with Vertex " << i << endl;
		G.tree_level(i, 0);
	}
	system("PAUSE");
}
