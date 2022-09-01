class Base {
public:
   void f(int){}
};

class Derived : public Base {
public:
   void f(double, int) {}
};

int main() {
   int i;
   Derived d;
   d.f(i);     // error!
}

/* Output:
Hide.cpp: In function int main():
Hide.cpp:19: error: no matching function for call to Derived::f(int&)
Hide.cpp:12: note: candidates are: void Derived::f(double, int)
*/

