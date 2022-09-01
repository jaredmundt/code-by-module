// deleter1.cpp: Illustrates unique_ptr with a deleter
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <memory>
using namespace std;

void deleter(FILE* f) {
    fclose(f);
    cout << "FILE* closed\n";
}

int main() {
    // The following uses a deleter, but no wrapper class!
    FILE* f = fopen("deleter1.cpp", "r");
    assert(f);
    unique_ptr<FILE, function<void(FILE*)>> anotherFile(f,&deleter);

    // Could just do this (but there would be no trace)
    FILE* f2 = fopen("deleter1.cpp", "r");
    assert(f2);
    unique_ptr<FILE, function<int(FILE*)>> the3rdFile(f2,&fclose);
}

/* Output:
FILE* closed
*/
