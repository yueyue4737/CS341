// a basic class structure

#include <cstdlib>
#include <iostream>
using namespace std;

class  FirstClass {
public: // how to use the variable in the private field
	void putNr(int x) { nr = x; }
	int    getNr() { return nr; }
private:
	int  nr;
};
int main() {
	FirstClass A;
	A.putNr(5);
	cout << "Value of data member in A object is "
		<< A.getNr() << endl;
	return EXIT_SUCCESS;
}
