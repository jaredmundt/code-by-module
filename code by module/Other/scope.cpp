#include <iostream>
using namespace std;

int i = 10;

int main()
{
   cout << i << endl;

   int i = 20;
   cout << i << endl;

   {
      int i = 30;
      cout << i << endl;
      cout << ::i << endl;
   }
}

/* Output:
10
20
30
10
*/

