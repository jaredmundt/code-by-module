int main() {
    enum {n = 7};
    auto p = &n;        // fails
    const int m = 7;
    auto q = &m;        // OK
}

/* Error message:
/Users/chuck/UVU/3370/rvalue.cpp:3:14: error: cannot take the address of an rvalue of type '<anonymous enum at /Users/chuck/UVU/3370/rvalue.cpp:2:5>'
*/