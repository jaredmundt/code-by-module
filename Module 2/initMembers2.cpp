#include <iostream>
using namespace std;

class Member1
{
   int x=0;
public:
   Member1() {
      cout << "Constructing a default Member1 object\n";
   }
   Member1(int x)   {
      cout << "Constructing a Member1 object\n";
      this->x = x;
   }
};


class Member2 {
   int y=0;
public:
   Member2() {
      cout << "Constructing a default Member2 object\n";
   }
   Member2(int y) {
      cout << "Constructing a Member2 object\n";
      this->y = y;
   }
};

class Wrapper {
   Member2 mem2;
   Member1 mem1;
   int z;
public:
   Wrapper(int x, int y, int z)  {
      cout << "Constructing a Wrapper\n";
      mem2 = Member2(y);
      mem1 = Member1(x);
      this->z = z;
   }
};

int main() {
   Wrapper w(1,2,3);
}

