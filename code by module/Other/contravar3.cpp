// contravar3.cpp: Illustrates contravariance of preconditions and covariance of post-conditions
#include <cassert>
#include <stdexcept>
using namespace std;

// In the example below, Base::f requires odd input and returns an even number.
// Derived::f weakens the precondition and strengthens the post-condition.
// Substitutability is maintained and the Base "contract" is satisfied.

class Base {
public:
    virtual int f(int x) {
        if (x % 2 == 0)
            throw logic_error("Pre-condition violation; x must be odd");
        int retval = 0;
        // Compute final retval...
        assert(x % 2 == 0);     // Post-condition: x is even
        return x;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    virtual int f(int x) {
        // Pre-condition: x is an integer
        
        return 8;   // Post-condition: x == 8 (which is even)
    }
};