// contravar.cpp: Illustrates Contravariant parameter types (broken in C++)

#include <iostream>
using namespace std;

struct BaseParm {};
struct DerParm : BaseParm {};

struct Base
{
   virtual void f(DerParm*) {cout << "Base::f\n";}
};

struct Derived : Base
{
   void f(BaseParm*) {cout << "Derived::f\n";}  // Problem: Hides Base::f (a different function altogether)
};

int main()
{
   Base* bp = new Derived;
   bp->f(new DerParm);
   bp->f(new BaseParm); // Error!
}

