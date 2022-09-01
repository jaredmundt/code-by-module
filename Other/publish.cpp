// Illustrates private inheritance

class Base
{
public:
   void f() {}
   void g() {}
};

class Derived : Base 	// private inheritance
{
public:
   using Base::f;   // makes f public for clients (overrides private due to inheritance)
   void h() {
      f();          // Derived can always access non-private
      g();          // members of Base, as usual.
   }
};

int main() {
   Derived d;
   d.h();   // okay
   d.g();   // error
   d.f();   // okay
}

/* Compiler output:
/Users/chuck/UVU/3370/code/publish.cpp: In function 'int main()':
/Users/chuck/UVU/3370/code/publish.cpp:7:9: error: 'void Base::g()' is inaccessible
/Users/chuck/UVU/3370/code/publish.cpp:23:8: error: within this context
/Users/chuck/UVU/3370/code/publish.cpp:23:8: error: 'Base' is not an accessible base of 'Derived'
*/


