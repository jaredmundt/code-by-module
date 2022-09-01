#include <iostream>
using namespace std;

int (*f())[2]
{
   return new int[7][2];
}

int main()
{
   int (*p)[2] = f();
   cout << sizeof(p[0]) << endl;        // 8
   cout << sizeof(p[0][0]) << endl;     // 4
   delete [] p;
}
