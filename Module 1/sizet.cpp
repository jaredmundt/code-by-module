#include <cstddef>
#include <iostream>
using namespace std;

int main() {
	cout << typeid(size_t).name() << ',' << sizeof(size_t) << endl;
	cout << typeid(1UL).name() << ',' << sizeof(1UL) << endl;
}
