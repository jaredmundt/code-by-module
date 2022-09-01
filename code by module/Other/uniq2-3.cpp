// uniq2-3.cpp: A unique that works on unsorted sequences
// Outputs as it goes
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include "copy_if.h"
using namespace std;

namespace {
    set<string> words;
    // A function that conditionally accepts input words
    bool first_word(const string& s) {
        bool first_time = words.find(s) == words.end();
        if (first_time)
            words.insert(s);
        return first_time;
    }
}

int main() {
   // Read strings into memory
   copy_if(istream_iterator<string>(cin), istream_iterator<string>(),
           ostream_iterator<string>(cout,"\n"), first_word);
}

