// plus.cpp: Illustrate a plus function object
#include <iostream>
#include <string>
using namespace std;

template<class T>
struct Plus {
    T operator()(const T& m, const T& n) {
        return m+n;
    }
};

int main() {
    Plus<int> p;
    cout << p(2,3) << endl;             // 5
    
    Plus<string> p2;
    cout << p2("carrot","top") << endl; // carrottop
}