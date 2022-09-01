#include <cstddef>
#include <cstdio> // For BUFSIZ
#include <cstring>
#include <iostream>
using namespace std;

int comp(const void*, const void*);

int main()
{
   const size_t MAXLINES = 100;
   char *strings[MAXLINES], buf[BUFSIZ];
   size_t n = 0;
   while (n < MAXLINES && cin.getline(buf, sizeof(buf)))
   {
      strings[n] = new char[strlen(buf)+1];
      strcpy(strings[n++], buf);
   }

   // Sort & print
   qsort(strings, n, sizeof(strings[0]), comp);
   for (size_t i = 0; i < n; ++i) {
      cout << strings[i] << endl;
      delete [] strings[i];
   }
}

int comp(const void* p1, const void* p2)
{
   const char* s1 = *static_cast<const char* const*>(p1);
   const char* s2 = *static_cast<const char* const*>(p2);
   return strcmp(s1, s2);
}
