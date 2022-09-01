// uniq2.c: A unique that works on unsorted sequences
// The original sequence is left undisturbed
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

namespace 
{
   vector<string> words;   // The vector of words

   // Sort Predicates: Compare strings through an index
   bool less_by_idx(int a, int b) {
      return words[a] < words[b];
   }
   bool equal_by_idx(int a, int b) {
      return words[a] == words[b];
   }
   void print_word(int idx) {
       cout << words[idx] << endl;
   }

   // An identity generator
   int id() {
      // Returns 0 through whatever, 1 at a time
      static int n = 0;
      return n++;
   }
}

int main() {
   // Read strings into memory
   copy(istream_iterator<string>(cin), istream_iterator<string>(),
        back_inserter(words));

   // Create index vector
   vector<int> idx;
   generate_n(back_inserter(idx), words.size(), id);

   // Sort strings via index
   stable_sort(idx.begin(), idx.end(), less_by_idx);

   // Remove indexes to duplicate lines
   vector<int>::iterator uniq_end = unique(idx.begin(), idx.end(), equal_by_idx);

   // Restore original order of remaining lines
   sort(idx.begin(), uniq_end);

   // Output unique lines through index
   for_each(idx.begin(), uniq_end, print_word);
}

