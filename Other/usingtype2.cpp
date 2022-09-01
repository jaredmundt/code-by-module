#include <iostream>
using namespace std;

int main() {
    using pstring = char*;
    
    // cstr is a const pointer to char
    const pstring cstr = nullptr;

    // ps is a pointer to a const pointer to char
    const pstring *ps;
}
