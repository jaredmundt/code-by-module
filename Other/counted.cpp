// counted.cpp
#include <cassert>
#include <iostream>
using namespace std;

/*
Description:
	Clients derive from this abstract class to obtain
	class reference-counting semantics. To properly
	use this class, derived classes should keep their
	constructors protected and provide a separate, static
	factory function to clients. This "create" function
	should return a pointer to a new derived object on
	the heap, after calling attach() to register with
	Counted. Clients then call detach() on the derived
	object to remove their interest in the counted object.
	This way multiple clients can share a derived object.
	Derived objects will not be destroyed until the last
	client calls detach().
*/

class Counted {
public:
	int attach() { return ++_refcount; };
	int detach() {
        return (_refcount > 0) ? ((--_refcount > 0) ? _refcount
		                                            : (delete this, 0))
		 	                   : 0;
    }
	int refcount() const { return _refcount; }

protected:
	Counted(int n = 0) { _refcount = n; }
	virtual ~Counted() {
        assert(_refcount == 0);
        cout << "Counted subobject destroyed\n";
    }

private:
	int _refcount;
};

// Make Resource a reference-counted class:
class Resource : public Counted {
   // Note: no public constructors!
    Resource() = default;
public:
    static Resource* Create() {     // Factory method
        Resource* p = new Resource;
        p->attach(); // Initial attach
        return p;
    }
    ~Resource() { cout << "Resource destroyed\n"; }
};

// A Client uses a Resource
class Client
{
public:
    Client(Resource* p) {
        pRes = p;
        pRes->attach();
    }
    ~Client() {
        pRes->detach();
        cout << "Client object destroyed\n";
    }

private:
    Resource* pRes;
};

int main() {
    Resource* pR;
    {
        // Create a Resource to be shared:
        pR = Resource::Create();	         
        cout << pR->refcount() << endl;     // count is 1
      
        // Use the Resource in 2 clients:
        Client b1(pR);                 		
        cout << pR->refcount() << endl;     // count is 2
        Client b2(pR);                 		
        cout << pR->refcount() << endl;     // count is 3
      
        // Undo the original Attach:
        pR->detach();               		   
        cout << pR->refcount() << endl;     // count is 2
      
        // b2.~Client() will reduce count to 1.
        // b1.~Client() will reduce count to 0
        // ...after which the Resource will self-destruct.
   }
}

/* Output:
1
2
3
2
Client object destroyed
Resource destroyed
Counted subobject destroyed
Client object destroyed
*/
