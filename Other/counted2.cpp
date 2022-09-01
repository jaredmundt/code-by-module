// counted2.cpp: Uses shared_pointer
#include <cassert>
#include <iostream>
#include <memory>
using namespace std;

class Resource {
   // Note: no public constructors!
    Resource() = default;
public:
    static Resource* Create() {     // Factory method
        Resource* p = new Resource;
        return p;
   }
   ~Resource() { cout << "Resource destroyed\n"; }
};

// A Client uses a Resource
class Client
{
public:
    Client(shared_ptr<Resource> p) : pRes(p) {}
    ~Client() { cout << "Client object destroyed\n"; }

private:
    shared_ptr<Resource> pRes;
};

int main() {
    // Create a Resource to be shared:
    shared_ptr<Resource> pR(Resource::Create());	 
    cout << pR.use_count() << endl;     // count is 1
  
    // Use the Resource in 2 clients:
    Client b1(pR);                 		
    cout << pR.use_count() << endl;     // count is 2
    Client b2(pR);                 		
    cout << pR.use_count() << endl;     // count is 3
  
    // b2.~Client() will reduce count to 2.
    // b1.~Client() will reduce count to 1.
    // pR.~shared_ptr<Resource>() will reduce the count to 0.
    // ...after which the Resource will self-destruct.
}

/* Output:
1
2
3
Client object destroyed
Client object destroyed
Resource destroyed
*/
