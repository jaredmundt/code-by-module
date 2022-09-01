#include <cstddef>    // defines size_t (and other things we're not using yet)
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

class MyClass {
   int x;
   int y;
public:
   // These are all implicitly static member functions...
   static void* operator new(size_t siz) {
      void* p = ::operator new(siz);    // global operator new
      cout << "Allocating a MyClass object (" << siz << " bytes) at " << p << '\n';
      return p; 

   }
   
   static void operator delete(void* p) noexcept {
      cout << "Deleting a MyClass object at " << p << '\n';
      ::operator delete(p);
   }
   
   static void* operator new[](size_t siz) {
      void* p = ::operator new[](siz);
      std::printf("Allocating an array of MyClass objects (%lu bytes) at %p\n", siz, p);
      return p; 
   }
   
   static void operator delete[](void* p) noexcept {
      std::printf("Deleting an array of MyClass objects at %p\n", p);
      ::operator delete[](p);
   }
};

int main() {
   MyClass* p1 = new MyClass;
   MyClass* p2 = new MyClass[10];
   delete p1;
   delete [] p2;
}

/* Output:
Allocating a MyClass object (8 bytes) at 0x7fd6a2c03910
Allocating an array of MyClass objects (80 bytes) at 0x7fd6a2c03920
Deleting a MyClass object at 0x7fd6a2c03910
Deleting an array of MyClass objects at 0x7fd6a2c03920
*/
