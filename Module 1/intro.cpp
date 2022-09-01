// intro.cpp: Selected modern C++ features

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    vector v{1,2,3};    // Infer element types from initializer
    for (int n: v)      // Range-based for loop
        cout << n << '\n';

    // Populate new vector based on v (add 2)
    // Uses lambda expression, transform and copy algorithms, ostream_iterator
    vector<int> w(v.size());
    transform(begin(v),end(v),begin(w),[](int n){return n+2;});
    copy(begin(w),end(w),ostream_iterator<int>(cout," "));
    cout << '\n';

    // Traverse w backwards
    // Uses auto, reverse iterators
    for (auto iter = rbegin(w); iter < rend(w); ++iter)
        cout << *iter << '\n';
}
