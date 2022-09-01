// Illustrates private inheritance

class Base
{
public:
   void f() {}
   void g() {}
};

class Derived : private Base
{
public:
   void h()
   {
      f();  // Derived can access non-private
      g();  // members of Base as usual.
   }
};

int main()
{
   Derived d;
   d.h();   // okay
   d.g();   // error
   d.f();   // error
}

/* Compiler output:
Error E2247 c:\uvsc\spring02\3370\private.cpp 24: 'Base::g()' is not accessible in function main()
Error E2247 c:\uvsc\spring02\3370\private.cpp 25: 'Base::f()' is not accessible in function main()
*/


