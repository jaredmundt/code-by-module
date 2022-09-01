#include <iostream>
using namespace std;

class Base
{
public:
   static int b;
   void f() {};
};

int Base::b = 1;

class Derived : public Base
{
public:
   enum {d = 2};
   void f(int) {};   // Don't do this!
};

int main()
{
   cout << Base::b << endl;      // 1
   cout << Derived::d << endl;   // 2
   Derived d;
   d.f(1);     // okay
   d.f();      // error!
}

/*
/Users/chuck1/Desktop/UVU/3370/code/classScope.cpp:26:6: error: too few arguments to function call, expected 1, have 0; did you mean 'Base::f'?
   d.f();      // error!
     ^
     Base::f
/Users/chuck1/Desktop/UVU/3370/code/classScope.cpp:8:9: note: 'Base::f' declared here
   void f() {};
        ^
1 error generated.
*/
