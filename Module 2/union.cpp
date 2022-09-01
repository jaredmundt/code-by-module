#include <iostream>
using namespace std;

struct IntOrString {
    bool is_int;    // A "tag" so we know what's in there
    union {         // Anonymous union; n and s are in the scope of Semipair
        int n;
        const char* s;
    };
};

void display_Semipair(const IntOrString& sp) {
    if (sp.is_int)
        cout << sp.n << endl;
    else
        cout << sp.s << endl;
}

int main() {
    IntOrString sp;
    sp.n = 7;
    sp.is_int = true;
    display_Semipair(sp);       // 7
    const char* s = "seven";
    sp.s = s;
    sp.is_int = false;
    display_Semipair(sp);       // seven
}