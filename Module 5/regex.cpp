#include <algorithm>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<string> findall(string s, string pat) {
    vector<string> v;
    regex r{pat};
    transform(sregex_iterator(begin(s),end(s),r),sregex_iterator(),back_inserter(v),
              [](smatch p){return p.str();});
    return v;
}

void display(const vector<string>& v) {
    cout << v.size() << ": ";
    copy(begin(v),end(v),ostream_iterator<string>(cout," "));
    cout << '\n';     
}

int main() {
    string s{"This his history."};

    // Find occurrences of "his"
    auto results = findall(s,"his");
    display(results);

    // Find occurrences of strings starting with "his" (note count! - maximal string)
    results = findall(s,"his.*");
    display(results);

    // Find occurrences of strings starting with "his" (note count! - minimal string)
    results = findall(s,"his.*?");
    display(results);

    // Find occurences of "his" at the end of a word
    results = findall(s,R"(his\b)");
    display(results);

    // Find words that begin with "his"
    results = findall(s,R"(\bhis\w*)");
    display(results);

    // Find words that begin with "his" but have at least one more "word" character
    results = findall(s,R"(\bhis\w+)");
    display(results);

    // Find word suffixes of length 4 that end in "his"
    results = findall(s,R"(\whis\b)");
    display(results);

    // Find word suffixes of length 3 or more that end in "his"
    results = findall(s,R"(\w*his\b)");
    display(results);

    // Find words that begin with 'T' or end with 'y'
    results = findall(s,R"(\bT\w+|\w+y\b)");
    display(results);

    // Find all words
    results = findall(s,"[[:alpha:]]+");    // Same as [a-zA-Z]+
    display(results);

    // Find all lower-case substrings
    results = findall(s,"[[:lower:]]+");    // Same as [a-z]+
    display(results);

    // Find all lower-case substrings
    results = findall(s,"[[:upper:]]+");    // Same as [A-Z]+
    display(results);

    // Find all punctuation substrings
    results = findall(s,"[[:punct:]]+");
    display(results);

    // Find all space substrings
    results = findall(s,"[[:space:]]+");
    cout << results.size() << ": ";
    for_each(begin(results),end(results),[](string s){cout << '"' << s << "\", ";});
    cout << endl;
}

/* Output:
3: his his his 
1: his his history. 
3: his his his 
2: his his 
2: his history 
1: history 
1: this 
2: this his 
2: this history 
*/
