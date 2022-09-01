// pair.cpp
#include <iostream>
#include <tuple>
#include <typeinfo>
#include <utility>
using namespace std;

template<class T, class U>
void print_pair(const pair<T,U>& p) {
    cout << "first: " << p.first << ", second: " << p.second << endl;
}

int main() {
    pair<int,string> p1(10,"ten");
    print_pair(p1);
    auto p2 = make_pair(20,"twenty"s);  // string suffix
    print_pair(p2);
    auto [n,s] = p2;	// Structured binding
    cout << n << endl;
    cout << s << endl;
    tie(n,s) = p1;
    cout << n << endl;
    cout << s << endl;
}

/*
first: 10, second: ten
first: 20, second: twenty
20
twenty
10
ten
*/