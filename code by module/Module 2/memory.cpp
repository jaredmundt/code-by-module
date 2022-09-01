#include <cstddef>
#include <cstdlib>
#include <cstdio>

void* operator new(size_t siz) {
   void* p = std::malloc(siz);
   std::printf("Allocating %lu bytes at %p\n", siz, p);
   return p; 
}

void operator delete(void* p) noexcept {
   std::printf("Deleting memory at %p\n", p); // Can't use cout!
   std::free(p);
}

int main() {
   int* p1 = new int;
   int* p2 = new int[10];
   delete p1;
   delete [] p2;
}

/* Output:
Allocating 4 bytes at 0x7fb4e9403830
Allocating 40 bytes at 0x7fb4e9403840
Deleting memory at 0x7fb4e9403830
Deleting memory at 0x7fb4e9403840
*/
