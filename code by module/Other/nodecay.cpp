#include <array>
#include <iostream>
using namespace std;

template<typename T,size_t N>
void f(const array<T,N>& a) {       
    cout << typeid(a).name() << " (" << sizeof(a) << ")\n";
}

int main() {
    array<int,3> stuff  {1,2,3};
    cout << typeid(stuff).name() << " (" << sizeof(stuff) << ")\n";
    f(stuff);
}

/* Output:
St5arrayIiLm3EE (12)
St5arrayIiLm3EE (12)
*/