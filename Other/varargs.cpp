#include <iostream>
#include <list>
#include <vector>
using namespace std;

void args(const initializer_list<int>& stuff) {
    for (auto& arg: stuff)
        cout << arg << ' ';
    cout << endl;
}

void args2(const vector<int>& stuff) {
    for (auto& arg: stuff)
        cout << arg << ' ';
    cout << endl;
}

void args3(const list<int>& stuff) {
    for (auto& arg: stuff)
        cout << arg << ' ';
    cout << endl;
}

int main() {
    args({1,2,3});
    args2({4,5,6,7});
    args3({8,9,10});
}