#include <new>    // defines size_t (and other things we're not using yet)
#include <cstdlib>
#include <cstdio>
using namespace std;

class T {
   int x;
public:
   T() {
      printf("Default ctor\n");
   }
   ~T() {
      printf("Destructor\n");
   }
};


void* operator new(size_t siz) {
   void* p = std::malloc(siz);
   std::printf("Allocating %lu bytes at %p\n", siz, p);
   return p; 
}

void operator delete(void* p) noexcept {
   std::printf("Deleting memory at %p\n", p);
   std::free(p);
}

int main() {
   T* p1 = new T;
   T* p2 = new T[10];
   delete p1;
   delete [] p2;
}

/* Output:
Allocating 4 bytes at 0x7fbd48403830
Default ctor
Allocating 48 bytes at 0x7fbd48403840
Default ctor
Default ctor
Default ctor
Default ctor
Default ctor
Default ctor
Default ctor
Default ctor
Default ctor
Default ctor
Destructor
Deleting memory at 0x7fbd48403830
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Deleting memory at 0x7fbd48403840
*/
