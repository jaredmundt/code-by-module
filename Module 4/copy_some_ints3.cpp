// copy_some_ints3.cpp: Uses a lambda
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int main() {
  array<int,3> a = { 10, 20, 30 };
  decltype(a) b;
  auto endb = copy_if(begin(a), end(a), begin(b), [](int x){return x < 15;});
  auto beginb = begin(b);
  copy(begin(b),endb,ostream_iterator<int>(cout,"\n")); // 10
}