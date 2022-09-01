// convert.cpp: Conversion sequence: int -> double -> aType -> MyClass
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

int main() {
	MyClass m{1};
	cout << m << endl;	// 1
}