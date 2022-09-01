#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string,int> wc;
	ifstream f("Strings.txt");
	string word;
	while (f >> word)
		wc[word]++;
	for (auto [k,v]: wc) {
		cout << k << ": " << v << endl;
	}
}