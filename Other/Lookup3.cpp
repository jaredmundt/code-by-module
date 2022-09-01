class Base {
public:
   void f(int) {}
};

class Derived : public Base {
   void f(){}
};

int main() {
   Derived d;
   d.f(123);     // Line 17: Overload error!

   Base* p = &d;
   p->f(123);    // okay, looks in scope of Base
}

/* Output: (A bug in Borland)
/Users/chuck/UVU/3370/code/Lookup3.cpp: In function 'int main()':
/Users/chuck/UVU/3370/code/Lookup3.cpp:14:11: error: no matching function for call to 'Derived::f(int)'
/Users/chuck/UVU/3370/code/Lookup3.cpp:14:11: note: candidate is:
/Users/chuck/UVU/3370/code/Lookup3.cpp:9:9: note: void Derived::f()
/Users/chuck/UVU/3370/code/Lookup3.cpp:9:9: note:   candidate expects 0 arguments, 1 provided
*/
