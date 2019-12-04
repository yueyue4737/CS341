#include <iostream>
using namespace std;
#include <cstdlib>

class  FirstClass {
public:
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
