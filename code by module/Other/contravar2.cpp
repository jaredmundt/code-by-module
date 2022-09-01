// contravar2.cpp: Illustrates Contravariant pre-conditions

#include <iostream>
#include <cassert>
using namespace std;

struct BaseParm
{
   int x;
   BaseParm(int n) : x(n){}
};

struct Base
{
   virtual void f(BaseParm* p) {assert(10 <= p->x && p->x < 20);}
};

struct Derived : Base
{
   void f(BaseParm* p) {assert(0 <= p->x && p->x < 100);}
};

int main()
{
   Base* bp = new Derived;
   bp->f(new BaseParm(5)); // OK
   bp = new Base;
   bp->f(new BaseParm(5)); // Pre-condition violation
}

