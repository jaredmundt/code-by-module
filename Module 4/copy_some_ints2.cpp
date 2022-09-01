// copy_some_ints2.cpp: Uses bind with a function object
#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
  int a[]{ 10, 20, 30 };
  decltype(a) b;	// Array of 3 ints
  auto endb = copy_if(begin(a), end(a), begin(b), [](int n){return n > 15;});
  copy(begin(b),endb,ostream_iterator<int>(cout,"\n"));	
}