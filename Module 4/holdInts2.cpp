// Uses vector constructor to read an arbitrary number of ints from a file
#include <cassert>
#include <cstddef>   // For size_t
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
   ifstream ifs("nums.dat");
   vector<int> nums{istream_iterator<int>(ifs),istream_iterator<int>()};
   cout << "Read " << nums.size() << " numbers\n";
   for (auto i: nums)
      cout << i << ' ';
   cout << endl;
}

/* Outut from the command: $holdInts2 nums.dat:
Read 21 numbers
5737 8716 5982 1804 6148 7004 5861 8292 3958 8948 3307 7194 1748 4800 1660 4131 8275 7370 9081 6934 3220 
*/