#include <iostream>
using namespace std;

void display() {}

template<typename T, typename... Rest>
void display(T head, Rest... rest) {
    cout << typeid(T).name() << ": " << head << endl;
    display(rest...);
}

int main() {
    display("one",1,2.0);
}

/* Output:
PKc: one
i: 1
d: 2
*/