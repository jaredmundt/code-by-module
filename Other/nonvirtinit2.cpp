// nonvirtinit2.cpp
#include <iostream>
#include <string>
using namespace std;

class A {
public:
   A(const string& s) {
      cout << "A " << s << endl;
   }
};

class B {
public:
   B(const string& s) {
      cout << "B " << s << endl;
   }
};

class C {
public:
   C(const string& s) {
      cout << "C " << s << endl;
   }
};

class D {
public:
   D(const string& s) {
      cout << "D " << s << endl;
   }
};

class E : public A, public B, public C {
public:
   E(const string& s) : A("from E"), B("from E"), C("from E") {
      cout << "E " << s << endl;
   }
};

class F : public B, public C, public D {
public:
   F(const string& s) : B("from F"), C("from F"), D("from F") {
      cout << "F " << s << endl;
   }
};

class G : public E, public F {
public:
   G(const string& s) : E("from G"), F("from G") {
      cout << "G " << s << endl;
   }
};

int main() {
   G g("from main");
}

/* Output:
A from E
B from E
C from E
E from G
B from F
C from F
D from F
F from G
G from main
*/
