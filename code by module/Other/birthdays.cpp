// Shows that it takes 23 people to have a > 50% chance that two have same birthday

// Follows from the formula p = 1 - prod<k = 1,n-1>{(365-k+1)/365}
// The following code iterates until p < .5

#include <iostream>
using namespace std;

int main()
{
   double x = 2.0;
   double y = 1.0;
   int n = 1;
   cout << x << ',' << y << ',' << n << endl;
   while (x >= y)
   {
      x *= (365-n);
      y *= 365;
      ++n;
      cout << x << ',' << y << ',' << n << endl;
   }
   cout << n << endl; // 23
}

