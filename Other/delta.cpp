// delta.cpp: Shows offsets of inherited subobjects
#include <iostream>
using namespace std;

struct A {
   int x;
};
struct B {
   int y;
};
struct C  : A, B {
   int z;
};

int main() {
   C* pc = new C;
   cout << pc << endl;
   cout << &pc->z << endl;
   B* pb = pc;
   cout << pb << endl;
   cout << &pc->y << endl;
   A* pa = pc;
   cout << pa << endl;
   cout << &pc->x << endl;
   delete pc;
}

/* Output:
0x7fad02c000e0
0x7fad02c000e8
0x7fad02c000e4
0x7fad02c000e4
0x7fad02c000e0
0x7fad02c000e0
*/
