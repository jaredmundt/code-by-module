#include <iostream>
using namespace std;

class Base
{
public:
    virtual void printme() { cout << "Printing Base" << endl; }
};

class Derived1 : public Base
{
public:
    void printme() { cout << "Printing Derived1" << endl; }
};

class Derived2 : public Base
{
    int val;
public:
    void printme() { cout << "Derived 2, value: " << val << endl; }
    Derived2 (int v) : val(v) {};
};

void funref (Base& b)
{
	b.printme();
}
void funval (Base b)
{
	b.printme();
}

int main()
{
	Base baseobj;
	Derived1 d1_obj;
	Derived2 d2_obj(17653);

	cout << endl << "Passing Derived Objects by Reference: " << endl;
	funref(baseobj);
	funref(d1_obj);
	funref(d2_obj);

	cout << endl << "Passing Derived Objects by Value: " << endl;
	funval(baseobj);
	funval(d1_obj);
	funval(d2_obj);
}

/* Output:
Passing Derived Objects by Reference: 
Printing Base
Printing Derived1
Derived 2, value: 17653
*/
