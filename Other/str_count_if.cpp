#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s("Now is the time!");
    auto t_count = count (begin(s), end(s), 't');
    cout << "Number of t's : " << t_count << endl;

    auto lc_count = count_if (begin(s), end(s),
		    [] ( char x) { return islower(x); });
    cout << "Number of lower case characters: " << lc_count << endl;
}
