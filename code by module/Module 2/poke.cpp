#include <iomanip>
#include <iostream>
#include <new>
using namespace std;

template<typename T>
T peek(void* p) {
    // Return the bytes at address p interpreted as a T object
    return *static_cast<T*>(p); // Casting from void* only requires a static_cast
}

template<typename T>
void poke(void* p, T t) {
    // Place a copy of the object t at address p
    new (p) T(t);   // "Placement new"
}

struct Foo {
    int n;
    double x;
    Foo(int en, double ex) : n{en}, x{ex} {}
};

int main() {
    char *raw_bytes{new char[sizeof(int) + sizeof(Foo)]};
    
    // Place an int in the beginning of raw_data
    poke(raw_bytes,7);
    
    // Place a Foo right after that
    poke(raw_bytes+sizeof(int),Foo(2,3.5));
    
    // Retrieve the int
    int n = peek<int>(raw_bytes);
    cout << n << endl;                  // 7
    
    // Retrieve the Foo
    auto f = peek<Foo>(raw_bytes+sizeof(int));
    cout << f.n << ", " << f.x << endl; // 2, 3.5
}

/* Output:
7
2, 3.5
*/
