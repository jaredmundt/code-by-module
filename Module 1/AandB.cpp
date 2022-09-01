// Shows classes that hold a pointer to each other.
class A;	// A "forward" declaration for A (yet to be defined)

class B {   // A class definition
    A* ptrA;
    // ...
};

class A {   // A class definition
    B* ptrB;
    // ...
};
