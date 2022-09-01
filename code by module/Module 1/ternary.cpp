#include <iostream>
using namespace std;

int main()
{
   bool flag = true;
   int count1 = 0, count2 = 0;
   (flag ? count1 : count2) = 4;
   cout << count1 << ',' << count2 << endl;

   int n = !flag ? count1 : count2;
   cout << n << endl;
}
