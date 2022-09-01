//
// Memberwise copy is not the same as bitwise copy
// in a copy constructor
//

#include <iostream>
using namespace std;

class Foo
{
public:
	Foo(const Foo& f) {
		cout << "Copying a Foo" << endl;
		num = f.num + 1;
	}
	Foo () : num(1) {}
	int value() { return num; }
private:
	int num;
};

class Goo
{
public:
	int foovalue() {
		return myfoo.value();
	}
private:
	Foo myfoo;
};

int main()
{
	Goo g1;
	Goo g2 = g1;
	Goo g3(g2);

	cout << "g1: " << g1.foovalue() << endl;
	cout << "g2: " << g2.foovalue() << endl;
	cout << "g3: " << g3.foovalue() << endl;
}

// Output:
//
// Copying a Foo
// Copying a Foo
// 1
// 2
// 3
