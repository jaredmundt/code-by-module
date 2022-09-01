// range_based.cpp: Illustrates range-based container algorithms
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    // Start with an array of random numbers
    array<int,10> a;
    generate_n(a.begin(), a.size(), rand);
    
    // Don't do this!!! (Creation)
    vector<int> v1;
    copy(a.begin(), a.end(), back_inserter(v1));
    
    // Do this instead*
    vector<int> v2(a.begin(), a.end());    
    assert(equal(v1.begin(), v1.end(), v2.begin()));
    
    // Don't do this!!! (Insertion)
    array<int,5> b = {1,2,3,4,5};
    copy(b.begin(), b.end(), inserter(v1,v1.begin()));
    
    // Do this instead*
    v2.insert(v2.begin(),b.begin(),b.end());
    assert(equal(v1.begin(), v1.end(), v2.begin()));
    
    // Don't do this!!! (Assignment)
    v1.clear();
    copy(b.begin()+2, b.end(), back_inserter(v1));
    
    // Do this instead*
    v2.assign(b.begin()+2, b.end());
    assert(equal(v1.begin(), v1.end(), v2.begin()));
    
    // To erase elements* (here we are erasing the first half):
    v1.erase(v1.begin(), v1.begin()+v1.size()/2);
    v2.erase(v2.begin(), v2.begin()+v2.size()/2);
    assert(equal(v1.begin(), v1.end(), v2.begin()));
}
