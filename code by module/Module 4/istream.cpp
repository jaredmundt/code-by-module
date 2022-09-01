#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    ifstream ifs("nums.dat");
    vector<int> v;
    transform(istream_iterator<int>(ifs),istream_iterator<int>(),back_inserter(v),
            [](int n){return -n;});
    if (ifs.eof())
        copy(begin(v),end(v),ostream_iterator<int>(cout,"\n"));
}