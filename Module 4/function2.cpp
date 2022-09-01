// function2.cpp: Makes the applicator a function object

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int add(int x, int y) {
    return x+y;
}

template<class ArgType, class FType>
struct Apply {
    ArgType arg1, arg2;
    Apply(ArgType arg1, ArgType arg2) : arg1(arg1), arg2(arg2) {}
    void operator()(FType f) {
        cout << f(2,3) << endl;
    }
};

int main() {
    typedef function<int(int,int)> FType;
    vector<FType> funs;
    funs.push_back(&add);
    funs.push_back([](int x,int y){return x+y;});
    for_each(funs.begin(), funs.end(), Apply<int,FType>(2,3));
}

/* Output:
5
5
*/