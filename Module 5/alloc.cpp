// Adapted from http://www.josuttis.com/cppcode/myalloc.hpp.html
#include <limits>
#include <iostream>
#include <memory>

template <class T>
class MyAlloc : public std::allocator<T> {
public:
   // Allocate space for (but don't initialize) "num" elements of type T
   T* allocate (size_t num, const void* = nullptr) {
       // Print message and allocate memory with global new
       std::cout << num << " elements of size " << sizeof(T);
       T* ret = static_cast<T*>(::operator new(num*sizeof(T)));
       std::cout << " allocated at: " << static_cast<void*>(ret) << std::endl;
       return ret;
   }
   // Deallocate storage "p" of deleted elements
   void deallocate (T* p, size_t num) {
       // Print message and deallocate memory with global delete
       std::cout << "deallocate " << num << " elements of size "
                 << sizeof(T) << " at: " << static_cast<void*>(p) << std::endl;
       ::operator delete(p);
   }
};

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int,MyAlloc<int>> v;
    for (int i = 0; i < 100; ++i)
        v.push_back(i);
    cout << "Calling resize" << endl;
    v.resize(257);
    v.push_back(201);
}

/* Output:
1 elements of size 4 allocated at: 0x7fb053c026b0
2 elements of size 4 allocated at: 0x7fb053c026c0
deallocate 1 elements of size 4 at: 0x7fb053c026b0
4 elements of size 4 allocated at: 0x7fb053c026b0
deallocate 2 elements of size 4 at: 0x7fb053c026c0
8 elements of size 4 allocated at: 0x7fb053c026d0
deallocate 4 elements of size 4 at: 0x7fb053c026b0
16 elements of size 4 allocated at: 0x7fb053c026f0
deallocate 8 elements of size 4 at: 0x7fb053c026d0
32 elements of size 4 allocated at: 0x7fb053c02730
deallocate 16 elements of size 4 at: 0x7fb053c026f0
64 elements of size 4 allocated at: 0x7fb053c027b0
deallocate 32 elements of size 4 at: 0x7fb053c02730
128 elements of size 4 allocated at: 0x7fb053c028b0
deallocate 64 elements of size 4 at: 0x7fb053c027b0
Calling resize
257 elements of size 4 allocated at: 0x7fb054000000
deallocate 128 elements of size 4 at: 0x7fb053c028b0
514 elements of size 4 allocated at: 0x7fb054005000
deallocate 257 elements of size 4 at: 0x7fb054000000
deallocate 514 elements of size 4 at: 0x7fb054005000
*/
