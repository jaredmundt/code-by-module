#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int comp(const void*, const void*);

int main()
{
   const size_t MAXLINES = 100;
   string strings[MAXLINES];
   size_t n = 0;
   while (n < MAXLINES && cin >> strings[n])
      ++n;

   // Sort & print
   qsort(strings, n, sizeof(strings[0]), comp);
   for (size_t i = 0; i < n; ++i)
      cout << strings[i] << endl;
}

int comp(const void* p1, const void* p2)
{
   const string s1 = *static_cast<const string*>(p1);
   const string s2 = *static_cast<const string*>(p2);
   return s1.compare(s2);
}
