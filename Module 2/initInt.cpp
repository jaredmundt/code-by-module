#include <iostream>
using namespace std;

int main() {
   int i;
   cout << i << endl;
   int j = int();
   cout << j << endl;
   int * p = new int;
   cout << *p << endl;
   delete p;
   p = new int();
   cout << *p << endl;

   // The following is NOT an int:
   int x();
   // ERROR: cout << x << endl;
}

/* Output on VC++:
4263199
0
3277192
0
*/

