// Program Name DeptEmployee.cpp   Author John Maslanka  copyright
// Date June 16, 2015
// Purpose   To demonstrate the comcept of Aggregation.  This program shows an 
//  Employee object which is dependent by reference on a Department object to
//  retain and provide related information to the Employee record as needed.

#include <iostream>
using namespace std;
#include <cstdlib>

class Department {
private:
	int deptcode;
public:
	Department() { deptcode = 0; }
	void  putCode(int x) { deptcode = x; }
	int   getCode() { return deptcode; }
};
class Employee {
private:
	int idno;
	Department* deptPtr;
	Employee() {} // default constructor
public:
	void   putIdno(int y) { idno = y; }
	int    getIdno() { return idno; }
	void   putDept(Department* x) { deptPtr = x; }
	Department*  getDept() { return deptPtr; }
	int    showDept() { return deptPtr->getCode(); }
	Employee(int d, Department *X) { idno = d; deptPtr = X; } // Overload Constructor
};

int main() {
	int a = 12345, b = 67, c = 89;
	Department A;       // Referenced object
	A.putCode(b);
	cout << "For Dept A, code = " << A.getCode() << endl;
	// Employee D;     // Referencing object
	// D.putIdno (a);
	// D.putDept (&A);
	Employee D(a, &A);
	cout << "For Employee " << D.getIdno() << " the Dept is "
		<< D.showDept() << endl;
	Department C;       // new Referenced object
	C.putCode(c);
	cout << "For Dept object C, id = " << C.getCode() << endl;
	D.putDept(&C);
	cout << "For Employee " << D.getIdno() << " the Dept is now "
		<< D.showDept() << endl;
	cout << "Program terminating" << endl;
	return EXIT_SUCCESS;
}
