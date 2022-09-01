// sortlambda.cpp
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main() {
    array<string,4> words = {"how", "now", "brown", "cow"};
    sort(words.begin(),words.end(),/*greater<>());*/
         [](auto& p,auto& q){return p > q;});
    copy(words.begin(),words.end(),ostream_iterator<string>(cout," "));
    cout << endl;
}

/* Output:
now how cow brown 
*/