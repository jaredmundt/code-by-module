// function.cpp: Illustrates std::function

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int add(int x, int y) {
    return x+y;
}

template<class F>
void apply(F f) {
    cout << f(2,3) << endl;
}

int main() {
    vector<function<int(int,int)>> funs;
    funs.push_back(&add);
    funs.push_back([](int x,int y){return x*y;});
    for_each(funs.begin(), funs.end(), &apply<function<int(int,int)>>);
}

/* Output:
5
6
*/