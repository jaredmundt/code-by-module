#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

int comp(const void*, const void*);

int main()
{
   const size_t MAXINTS = 100;
   int ints[MAXINTS];
   size_t n = 0;
   while (n < MAXINTS && cin >> ints[n])
      ++n;

   // Sort & print
   qsort(ints, n, sizeof ints[0], comp);
   for (size_t i = 0; i < n; ++i)
      cout << ints[i] << endl;
}

int comp(const void* p1, const void* p2)
{
   int i1 = *static_cast<const int*>(p1);
   int i2 = *static_cast<const int*>(p2);
   return i1 - i2;
}

