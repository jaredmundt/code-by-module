// Illustrates shared_ptr
#include <cassert>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
using namespace std;

void deleter(FILE* f) {
    fclose(f);
    cout << "FILE* closed\n";
}

int main() {
    // The following uses a deleter, but no 2nd template arg needed
    FILE* f = fopen("deleter2.cpp", "r");
    assert(f);
    shared_ptr<FILE> anotherFile(f, &deleter);

    // Could just do this (but there would be no trace)
    FILE* f2 = fopen("deleter2.cpp", "r");
    assert(f2);
    shared_ptr<FILE> yetAnother(f2, &fclose);
}

/* Output:
FILE* closed
*/
