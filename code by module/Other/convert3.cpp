// convert.cpp: Conversion sequence: int -> double -> aType -> MyClass -> AnotherClass
// One too many user-defined classes (run to see error)

#include <iostream>
using namespace std;

class aType {
	double x;
public:
	aType(double y) {x = y;}
	double getval() const {return x;}
};

class MyClass {
	aType a;
public:
	MyClass(const aType& y) : a(y) {}
	operator double() const {return a.getval();}
};

class AnotherClass {
	MyClass m;
public:
	AnotherClass(const MyClass& x) : m(x) {}
};

int main() {
	AnotherClass a{1};	// Error
}