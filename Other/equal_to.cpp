// equal_to.cpp

#include <iostream>
#include <string>
using namespace std;

template<class T>
struct EqualTo {
    bool operator()(const T& t1, const T& t2) {
        return t1 == t2;
    }
};

int main() {
    EqualTo<int> p;
    cout << p(2,2) << endl;             // 1
    
    EqualTo<string> p2;
    cout << p2("carrot","top") << endl; // 0    
}