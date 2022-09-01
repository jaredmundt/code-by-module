#include <iostream>
using namespace std;

class RAII {
    int n;
public:
    RAII(int n) {
        this->n = n;
        cout << "RAII initialized with " << n << "\n";
    }
    ~RAII() {
        cout << "RAII " << n << " destroyed\n";
    }
};

int main() {
    RAII r1(1);
    try
    {
        RAII r(2);
        throw ":-)";
    }
    catch(...){}
}

/* Output:
RAII initialized with 1
RAII initialized with 2
RAII 2 destroyed
RAII 1 destroyed
*/