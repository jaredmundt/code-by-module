// decay.cpp: Illustrates array name decay
#include <iostream>
using namespace std;

void f(int a[]) {       // same as (int* a)
    cout << typeid(a).name() << " (" << sizeof(a) << ")\n";
    // CAN'T use a range-based for loop here! a is a pointer, NOT an array.
}

int main() {
    int stuff[]{1,2,3};
    cout << typeid(stuff).name() << " (" << sizeof(stuff) << ")\n";
    f(stuff);
    // Can use a range-based for loop here, if desired.
}

/* Output:
/Users/chuck/UVU/3370/code/decay.cpp:5:47: warning: sizeof on array function parameter will return size of 'int *' instead of 'int []' [-Wsizeof-array-argument]
    cout << typeid(a).name() << " (" << sizeof(a) << ")\n";
                                              ^
/Users/chuck/UVU/3370/code/decay.cpp:4:12: note: declared here
void f(int a[]) {       // same as (int* a)
           ^
1 warning generated.
A3_i (12)
Pi (8)
*/