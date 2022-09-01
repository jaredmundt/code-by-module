// Illustrates protected inheritance

class Base {
public:
   void f() {}
   void g() {}
};

class Derived : protected Base {
public:
   using Base::f;
};

class MoreDerived : public Derived {
public:
   void h() {
      f();  // f and g are protected as far
      g();  // as MoreDerived is concerned.
   }
};

int main() {
   Derived d;
   MoreDerived m;

   m.h();   // okay
   m.f();   // okay
   d.f();   // okay
   m.g();   // error
   d.g();   // error
}

/* Compiler Output:
/Users/chuck/UVU/3370/code/publish2.cpp: In function 'int main()':
/Users/chuck/UVU/3370/code/publish2.cpp:6:9: error: 'void Base::g()' is inaccessible
/Users/chuck/UVU/3370/code/publish2.cpp:29:8: error: within this context
/Users/chuck/UVU/3370/code/publish2.cpp:29:8: error: 'Base' is not an accessible base of 'MoreDerived'
/Users/chuck/UVU/3370/code/publish2.cpp:6:9: error: 'void Base::g()' is inaccessible
/Users/chuck/UVU/3370/code/publish2.cpp:30:8: error: within this context
/Users/chuck/UVU/3370/code/publish2.cpp:30:8: error: 'Base' is not an accessible base of 'Derived'
*/
