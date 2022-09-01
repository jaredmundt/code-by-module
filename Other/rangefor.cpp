// rangefor.cpp
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	vector<int> v = {1,2,3};
	for(auto i: v)
		cout << i << ' ';
	cout << endl;
	
    int a[] = {4,5,6};
    for (auto i: a)
        cout << i << ' ';
	cout << endl;
	
    map<string,int> m = {{"one", 1},{"two",2}};
    for (auto p: m)		// Old-fashioned way; prefer structured bindings)
        cout << p.first << ',' << p.second << ' ';
	cout << endl;
	
    unordered_set<int> u = {4,4,4,4,5,5,5,5,5,1,2,2,3,3,3};
    for (auto i: u)
        cout << i << ' ';
	cout << endl;
}

/* Output:
1 2 3 
4 5 6 
one,1 two,2 
3 2 1 5 4
*/