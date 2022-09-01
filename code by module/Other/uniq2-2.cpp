// uniq2-2.cpp: A unique that works on unsorted sequences
// Outputs as it goes
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <set>
using namespace std;

namespace {
    set<string> words;
    // A function that conditionally accepts input words
    bool test_word(const string& s) {
        int count = words.count(s);
        if (count == 0)
            words.insert(s);
        return count != 0;
    }
}

int main() {
   // Read strings into memory
   remove_copy_if(istream_iterator<string>(cin), istream_iterator<string>(),
        ostream_iterator<string>(cout,"\n"), test_word);
}

