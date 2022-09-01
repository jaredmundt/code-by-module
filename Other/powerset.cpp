#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
using namespace std;

template<class Seq>
vector<Seq> powerset(const Seq& s) {
    vector<Seq> result;
    result.push_back(Seq()); // Insert empty set

    auto siter = s.begin();
    while (siter != s.end()) {
        auto item = *siter++;
        // Add item to each set in result, forming new sets
        int curr_size = result.size();
        for (int i = 0; i < curr_size; ++i) {
            Seq new_set(result[i]);
            new_set.push_back(item);
            result.push_back(new_set);
        }
    }
    return result;
}

template<class Seq>
void print_set(const Seq& s) {
    cout << "{ ";
    copy(s.begin(), s.end(), ostream_iterator<typename Seq::value_type>(cout," "));
    cout << "}\n";
}

template<class PSet>
void print_sets(const PSet& s) {
    // PSet must be a sequence type containing other sequences
    for_each(s.begin(), s.end(), &print_set<typename PSet::value_type>);
}

template<class Set>
void print_powerset(const Set& s) {
    cout << "\nThe power set of ";
    print_set(s);
    cout << "is:\n";
    print_sets(powerset(s));
}

int main() {
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    print_powerset(s);
    vector<string> s2;
    s2.push_back("one");
    s2.push_back("two");
    s2.push_back("three");
    s2.push_back("four");
    print_powerset(s2);
}

/* Output:

The power set of { 1 2 3 }
is:
{ }
{ 1 }
{ 2 }
{ 1 2 }
{ 3 }
{ 1 3 }
{ 2 3 }
{ 1 2 3 }

The power set of { one two three four }
is:
{ }
{ one }
{ two }
{ one two }
{ three }
{ one three }
{ two three }
{ one two three }
{ four }
{ one four }
{ two four }
{ one two four }
{ three four }
{ one three four }
{ two three four }
{ one two three four }
*/
