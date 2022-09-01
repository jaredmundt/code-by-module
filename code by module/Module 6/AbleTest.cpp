// AbleTest.cpp: Uses Template Method for Printable
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<class T>
string toString(const T& t) {
    ostringstream os;
    os << t;
    return os.str();
}

class Printable {
public:
   void print(ostream& w) const {
      w << printrep();
   }
   virtual ~Printable() {}
protected:
   virtual string printrep() const = 0;
};

class Intable {
public:
   virtual int toInt() const = 0;
   virtual ~Intable() {}
};

class Stringable {
public:
   virtual string toString() const = 0;
   virtual ~Stringable() {}
};

class Able : public Printable, public Intable, public Stringable {
   int myData;
public:
   Able(int x) {
      myData = x;
   }
   int toInt() const {
      return myData;
   }
   string toString() const {
      return ::toString(myData);
   }
protected:
   string printrep() const {
      return toString();
   }
};

void testPrintable(const Printable& p) {
   p.print(cout);
   cout << '\n';
}

void testIntable(const Intable& n) {
   int i = n.toInt() + 1;
   cout << i << endl;
}

void testStringable(const Stringable& s) {
   cout << s.toString() << "th\n";
}

int main() {
   Able a(7);
   testPrintable(a);
   testIntable(a);
   testStringable(a);
}

/* Output:
7
8
7th
*/
