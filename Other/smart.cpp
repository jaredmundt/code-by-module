#include <iostream>
#include <typeinfo>
using namespace std;

struct Foo {
    int x;
};

template<class T>
class Pointer {
    T* thePtr;
    
    // Disable copy/assign
    Pointer(Pointer<T>&);
    Pointer<T>& operator=(const Pointer<T>&);
    
public:
    explicit Pointer(T* p) {
        cout << "holding " << static_cast<void*>(p) << '\n'; 
        thePtr = p;
    }
    ~Pointer() {
        cout << "deleting " << static_cast<void*>(thePtr) << '\n';
        delete thePtr;
    }
    T* operator->() {
        cout << "Pointer<T>::operator->\n";
        return thePtr;
    }
    T& operator*() {
        cout << "Pointer<T>::operator*\n";

        return *thePtr; 
    }
};

template<class P>   // assumes P is a smart pointer
class Wrapper {
    P& ptr;
public:
    explicit Wrapper(P& p) : ptr(p) {}
    P& operator->() {
        cout << "Wrapper<T>::operator->\n";
        return ptr;
    }
};

int main() {
    Pointer<int> p(new int(7)); // wrap an int*
    cout << *p << endl;

    Foo* f = new Foo;
    f->x = 10;
    Pointer<Foo> p2(f);         // wrap a Foo*
    cout << p2->x << endl;

    Wrapper<Pointer<Foo> > p3(p2);  // show multi-call ->
    cout << p3->x << endl;
}

/* Output:
holding 0x100200080
Pointer<T>::operator*
7
holding 0x100200090
Pointer<T>::operator->
10
Wrapper<T>::operator->
Pointer<T>::operator->
10
deleting 0x100200090
deleting 0x100200080
*/