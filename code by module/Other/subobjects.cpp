#include <iostream>
using namespace std;
class A
{
   int x;
};

class B : virtual public A
{
   int y;
};

class C : virtual public B
{
   int z;
};

int main()
{
   C c;
   cout << &c << endl;
   B* pb = &c;
   cout << pb << endl;
   A* pa = &c;
   cout << pa << endl;

}
