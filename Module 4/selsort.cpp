#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

// The simplest selection sort that could possibly work?
template<typename Iter>
void selsort(Iter beg, Iter end) {
   for (; beg != end-1; ++beg)
      iter_swap(beg, min_element(beg, end));
}

template<typename Iter>
bool isSorted(Iter beg, Iter end) {
   return adjacent_find(beg, end, greater<>()) == end;
}

int main() {
   array<int,5> a = {5,4,3,2,1};
   selsort(begin(a), end(a));
   assert(isSorted(begin(a),end(a)));
   cout << endl;
}
