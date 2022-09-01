// sortInvariant.cpp: Illustrates a Loop Invariant for Selection Sort
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
using namespace std;

inline void check_invariant(int* a, int i) {
#if !NDEBUG
    for (int j = 0; j < i-1; ++j)
        assert(a[j] <= a[j+1]);
#endif        
}

void mysort(int* a, int n) {
    int i = 0;
    // Invariant: "The first i elements are in ascending order" (0 to start)

    check_invariant(a, i);
    while (i < n) {
        // Invariant: "The first i elements are in ascending order"
        check_invariant(a, i);

        // Put the smallest element at the current "top"
        int* smallpos = min_element(a+i, a+n);
        iter_swap(a+i, smallpos);   // Swaps contents via pointers
        ++i;
    }
    // Invariant: "The first i elements are in ascending order"
    // ^ Loop termination: i == n
    // => array is sorted
    assert(i == n);
    check_invariant(a, i);
}

int main() {
    int a[] = {5,4,1,3,2};
    const int n = sizeof a / sizeof a[0];
    mysort(a, n);
    copy(a, a+n, ostream_iterator<int>(cout, " ")); // 1 2 3 4 5
    cout << endl;
}