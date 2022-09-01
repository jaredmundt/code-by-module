// copy_some_ints.cpp: (Don't do it this way!)
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
using namespace std;

// You supply this predicate
bool lt15(int x) { return x < 15; }

int main() {
  int a[] = { 10, 20, 30 };
  decltype(a) b;
  int* endb = copy_if(begin(a), end(a), b, lt15);
  copy(begin(b),endb,ostream_iterator<int>(cout," "));
  cout << endl;
}