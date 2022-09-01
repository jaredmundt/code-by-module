// Illustrates protected inheritance

class Base
{
public:
   void f() {}
   void g() {}
};

class Derived : protected Base
{};

class MoreDerived : public Derived
{
public:
   void h()
   {
      f();  // f and g are protected as far
      g();  // as MoreDerived is concerned
   }
};

int main()
{
   Derived d;
   MoreDerived m;

   m.h();   // okay
   m.f();   // error
   d.f();   // error
}

/* Compiler Output:
protected.cpp: In function ‘int main()’:
protected.cpp:6: error: ‘void Base::f()’ is inaccessible
protected.cpp:29: error: within this context
protected.cpp:29: error: ‘Base’ is not an accessible base of ‘MoreDerived’
protected.cpp:6: error: ‘void Base::f()’ is inaccessible
protected.cpp:30: error: within this context
protected.cpp:30: error: ‘Base’ is not an accessible base of ‘Derived’
*/
