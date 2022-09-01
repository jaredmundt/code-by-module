#include <new>
#include <cstdio>
using namespace std;

class MyClass {
   int i;
   float x;
   static int nAllocs;
   static int nDeallocs;
   static int nArrayAllocs;
   static int nArrayDeallocs;
   static int nBytesAllocated;

public:
   MyClass(int i = 0, float x = 0.0) {
      printf("===> Creating a MyClass(%d,%f)\n", i, x);
      this->i = i;
      this->x = x;
   }
   ~MyClass() {
      printf("===> Deleting a MyClass(%d,%f)\n", i, x);
   }
   static void* operator new(size_t nbytes) {
      printf("===> Allocating %lu bytes for an object\n", nbytes);
      ++nAllocs;
      nBytesAllocated += nbytes;
      return ::operator new(nbytes);
   }
   static void operator delete(void* addr) noexcept {
      printf("===> Deallocating an object\n");
      ++nDeallocs;
      ::operator delete(addr);
   }
   static void* operator new[](size_t nbytes) {
      printf("===> Allocating %lu bytes for an array\n", nbytes);
      ++nArrayAllocs;
      nBytesAllocated += nbytes;
      return ::operator new[](nbytes);
   }
   static void operator delete[](void* addr) noexcept {
      printf("===> Deallocating an array\n");
      ++nArrayDeallocs;
      ::operator delete[](addr);
   }
   static void report() {
      printf("\n*******************\n");
      printf("MyClass Heap Report\n");
      printf("*******************\n");
      printf("%d object allocations\n", nAllocs);
      printf("%d array allocations\n", nArrayAllocs);
      printf("%d bytes allocated\n", nBytesAllocated);
      printf("%d object deallocations\n", nDeallocs);
      printf("%d array deallocations\n\n", nArrayDeallocs);
   }
};

int MyClass::nAllocs = 0;
int MyClass::nDeallocs = 0;
int MyClass::nArrayAllocs = 0;
int MyClass::nArrayDeallocs = 0;
int MyClass::nBytesAllocated = 0;

int main() {
   MyClass* p1 = new MyClass(1,2);
   MyClass::report();
   MyClass* p2 = new MyClass[10];
   MyClass::report();
   delete p1;
   MyClass::report();
   delete [] p2;
   MyClass::report();
}

/* Output:
===> Allocating 8 bytes for an object
===> Creating a MyClass(1,2.000000)

*******************
MyClass Heap Report
*******************
1 object allocations
0 array allocations
8 bytes allocated
0 object deallocations
0 array deallocations

===> Allocating 88 bytes for an array
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)
===> Creating a MyClass(0,0.000000)

*******************
MyClass Heap Report
*******************
1 object allocations
1 array allocations
96 bytes allocated
0 object deallocations
0 array deallocations

===> Deleting a MyClass(1,2.000000)
===> Deallocating an object

*******************
MyClass Heap Report
*******************
1 object allocations
1 array allocations
96 bytes allocated
1 object deallocations
0 array deallocations

===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deleting a MyClass(0,0.000000)
===> Deallocating an array

*******************
MyClass Heap Report
*******************
1 object allocations
1 array allocations
96 bytes allocated
1 object deallocations
1 array deallocations
*/
