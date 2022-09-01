// tuple.cpp
#include <cassert>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

// A tuple type
using MyTuple = tuple<int,string>;

// "Increment" tuple elements in new tuple
MyTuple incr(const MyTuple& t) {
    return MyTuple(get<0>(t)+1, get<1>(t) + "+one");
}

int main() {
    MyTuple tup0(1,"text");
    auto tup1 = incr(tup0);
    cout << get<0>(tup1) << ' ' << get<1>(tup1) << endl;
    
    auto tup2 = make_tuple(2,"text+one"s);
    assert(tup1 == tup2);
    
    auto [n,s] = incr(tup2);    // Structured binding
    cout << n << ' ' << s << endl;
    get<0>(tup2) = 4;
    tie(n,s) = incr(tup2);      // Structured assignment
    cout << n << ' ' << s << endl;
}

/* Output:
2 text+one
3 text+one+one
5 text+one+one
*/