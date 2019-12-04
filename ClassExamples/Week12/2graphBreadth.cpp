// Author: John Maslanka   Graph5C-BreadthOnlyC.cpp
// Date: 27-Dec-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0
// Elementary Illustration of a Directed Graph adapted from 
// Figures 15.2 and 15.3 in Main and Savitch, but terminal 
// input is available. The program asks the user how many
// vertices to enter. (MAX is 100.) If the user enters 100, 
// the vertex numbers are from 0 to 99. The user then enters the
// edges by giving the start vertex followed by the end vertex
// up to the product of the number of vertices times the 
// number of vertices less 1, or you can terminate edge input  
// with control-z. 
// Note: FWIW an edge looping back to its first 
// vertex is disallowed in this code.
// Upgrades 5/4/2019 JM (1) Allow recovery from non-numeric 
//   input of a vertex when producing an edge, 
//   (2) Display adjacency matrix
//   (3) Reorganize program main to allow incremental inputs.

#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;

const int MAX = 100;

class Graph {
private:
	bool    edge[MAX][MAX];  // Adjacency Matrix
	int     count_of_vertices;
	int		vflag[MAX];
public:
	Graph() { count_of_vertices = 0; }
	int size() const { return count_of_vertices; }

	void add_vertexes(const int);
	void add_edge(int source, int target);
	void remove_edge(int source, int target);
	bool get_edge(int a, int b) { return edge[a][b]; }
	bool is_edge(int, int) const;
	int  addOrRemoveAnEdge(int, int, char);
	void clear_vflags(int);
	void clear_vflag(int);
	void set_vflag(int);
	int  test_vflag(int);
	void display_adjacency_matrix(int);
	void display_first_neighbor_lists();
	void display_breadth_first_list(int);
};

void Graph::add_vertexes(const int nr)
{
	int x, y;
	count_of_vertices = nr;
	for (x = 0; x < nr; ++x)
		for (y = 0; y < nr; ++y)
			edge[x][y] = false;
}
void Graph::clear_vflags(int nr)
{
	int x;
	for (x = 0; x < nr; ++x)
		vflag[x] = 0;
}
void Graph::set_vflag(int nr)
{
	vflag[nr] = 1;
}
void Graph::clear_vflag(int nr)
{
	vflag[nr] = 0;
}
int Graph::test_vflag(int nr)
{
	return vflag[nr];
}
void Graph::add_edge(int source, int target)
{
	edge[source][target] = true;
}
void Graph::remove_edge(int source, int target)
{
	edge[source][target] = false;
}
bool Graph::is_edge(int source, int target) const
{
	return edge[source][target];
}
int Graph::addOrRemoveAnEdge (int x, int nr, char aOrR) {
	int i, j;
	cout << "Enter the two bounding vertexes of an edge or EOF and Enter to proceed to menu selections " << endl;
	cin >> i >> j;
	if (!cin.eof())
	{
		if (!cin.good())
		{
			cout << "Non-numeric input for an edge is Invalid. "
				<< "Please re-enter your two vertexes." << endl;
			cin.clear();
			cin.ignore(80, '\n');
		}
		else if (i < 0 || i >= nr || j < 0 || j >= nr)
			cout << "Invalid input. One or both coordinates out of range" << endl;
		else if (i == j)
			cout << "Beginning and terminating vertexes must not be the same." << endl;
		else if (is_edge(i, j) && (aOrR == 'A'))
			cout << "Edge already exists." << endl;
		else if (!(is_edge(i, j)) && (aOrR == 'R'))
			cout << "Edge not defined." << endl;
		else
		{
			if (aOrR == 'A') {
				add_edge(i, j);
				++x;
				 }
			else {
				// if (aOrR == 'R') {
					remove_edge(i, j);
					--x;
				}
		}
	}
	return x;
}
void Graph::display_adjacency_matrix(int nr) {
	cout << endl << "From|To" << '\t';
	for (int i = 0; i < nr; i++) {
		if (i < 10) 
			cout << ' ';
		cout << i;
		}
	cout << endl;
	for (int i = 0; i < nr; i++) {
		cout << endl << i << '\t';
		for (int j = 0; j < nr; j++) {
			cout << ' ' << edge[i][j];
		}
	}
	cout << endl << endl;
}
void Graph::display_first_neighbor_lists() {
	for (int i = 0; i < size(); ++i)
	{
		cout << "For Vertex " << i <<'\t';
		for (int j = 0; j < size(); ++j)
			if (is_edge(i, j))
				cout << "   " << j;
		cout << endl;
	}
}
void Graph::display_breadth_first_list(int z) {
		int que[201];
		int x = 0, y = 0;
		cout << endl
			<< "Breadth-First Traversal on Graph for Vertex " << z << endl;
		que[x++] = z;
		clear_vflags(size());
		while (x != y)
		{
			int i = que[y];
			int j;
			y++;
			if (!test_vflag(i))
				cout << " " << i;
			for (j = 0; j < size(); ++j)
				if (is_edge(i, j) && !test_vflag(i)) {
					que[x++] = j;
					cout << " ( " << i << " " << j << " ) ";  // 
			}
			cout << "|";
			set_vflag(i);
		}
		cout << endl;
//	}
}

int main() {
	Graph G;
	int i, j, nr, x;
	cout << "Enter number of entries on a side of your Adjacency Matrix (1 < nr <= 100) ";
	cin >> nr;
	if (cin.eof() || !cin.good() || nr < 2 || nr > MAX)
	{
		cout << "Invalid input for entries on a side of Adjacency Matrix. "
			<< "Program terminating." << endl;
		exit(1);
	}
	G.add_vertexes(nr);
	cout << "Number of entries on the side of your Adjacency Matrix is " << G.size() << endl << endl;
	cout << " Beginning and Terminating vertex numbers must be between 0 and "
		<< (nr - 1) << " inclusive" << endl;
	cout << "Beginning and terminating vertexes must not be "
		<< "the same for an edge in this graph." << endl;
	cout << "Enter EOF at keyboard to view displays." << endl;
	for (x = 0; !cin.eof() && x < (nr - 1)*(nr - 1);)
	{
		x = G.addOrRemoveAnEdge(x, nr, 'A');
	}
	cin.clear();  // Unblock next step to menu
	cin.ignore();

	cout << "Enter your operation using the capital letter shown in your selection." << endl;
	cout << "Add an edge, Remove an edge, display adjacency Matrix, display list of First neighbor vertexes, " << endl;
	cout << " display Breadth-first lists of neighbor vertexes, Help, Exit: ";
	string buffer;
	char op = ' ';
	while (!cin.eof() && op != 'E' && op != 'e')  // add to and use an Adjacency Matrix in this while loop
	{
		cout << "Enter your operation > ";
		cin >> buffer;
		if (!cin.eof()) {
			op = buffer[0];
			if (op != 'E' || op != 'e')
				switch (op)
				{
				case 'A': case 'a':
				{ x = G.addOrRemoveAnEdge(x, nr, 'A');
				  cin.clear();  // Unblock next step to menu
				  cin.ignore();
				  break;
				}
				case 'R': case 'r':
				{ cout << "Enter the two vertexes for your edge to remove: ";
				  x = G.addOrRemoveAnEdge(x, nr, 'R');
				  cin.clear();  // Unblock next step to menu
				  cin.ignore();
				  break;
				}
				case 'M': case 'm':
				{ cout << endl << "Adjacency Matrix  " << nr << " * " << nr << endl ;
				  G.display_adjacency_matrix(nr);
				  break;
				}
				case 'F': case 'f':
				{ cout << "List of First Neighbor Vertexes" << endl;
				  G.display_first_neighbor_lists();
				  break;
				}
				case 'B': case 'b':
				{ int x;
				  cout << "Please enter the number of the vertex for your list: ";
				  cin >> x;
				  if (!cin.eof() && cin.good()) {
					  if (x > -1 && x < nr) {
						  cout << "Breadth-First List of Neighbor Vertexes for vertex " << x << endl;
						  G.display_breadth_first_list(x);
					  }
					  else
						  cout << "Vertex number is out of bounds." << endl;
				  }
				  else
					  if (cin.eof())
						  op = 'E';
					  else {
						  cout << "Vertex number is invalid." << endl;
						  cin.clear();  // Unblock next step to menu
						  cin.ignore();
					  }
				  break;
				}
				case 'H': case 'h':
				{ cout << "Enter your operation using the capital letter shown in your selection." << endl;
				  cout << "Add an edge, Remove an edge, display adjacency Matrix, display list of First neighbor vertexes, "
					  << endl;
				  cout << " display Breadth-first lists of neighbor vertexes, Help, Exit: ";
				  break;
				}
				case 'E': case'e':
				{ op = 'E';
				  break;
				}
				default:
				{ cout << "Invalid input. Enter H for Help." << endl;
				  break;
				}
			}
		}
	}
}
