#include <iostream>
using namespace std;

class A {
  int x;
public:
  A() {x = 0;}
  A(int n) {
    x = n;
    cout << "A:" << x << endl;
  }
};

class B {
  int y;
public:
  B() {y = 0;}
  B(int n) {
    y = n;
    cout << "B:" << y << endl;
  }
};

class C {
  B b;
  A a;
public:
  C(int m, int n) /*: a(m), b(n)*/ {
    cout << "C:" << m << ',' << n << endl;
  }
};

int main()
{
  C c(1,2);
}

/* Output:
B:2
A:1
C:1,2
*/
