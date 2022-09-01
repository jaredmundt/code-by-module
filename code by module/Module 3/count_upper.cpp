#include <cctype>
#include <iostream>
using namespace std;

void lower(string& s) {
    for (auto &c: s)
        c = tolower(c);  
}

int main() {
    string s{"The BEST Show On Earth"};

    int n = 0;
    for (auto c: s)
        if (isupper(c))
            ++n;

    cout << n << endl;
    lower(s);
    cout << s << endl;
}

/* Output:
8
the best show on earth
*/
