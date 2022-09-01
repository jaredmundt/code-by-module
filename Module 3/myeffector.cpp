#include <iostream>
#include <limits>  // For numeric_limits::max()
#include <string>
using namespace std;


class NoChar {
	char noch;
	string str;
public:
	NoChar (char c, string s) : noch(c), str(s) {}
	friend ostream& operator<<(ostream& os, const NoChar& n) {
		for (auto c : n.str) {
			if (c != n.noch) os << c;
		}
		return os;
	}
};

int main() {
char badch;
string mystring;

	cout << "Enter the forbidden character: ";
	cin.get(badch);

	while (true) {
		cout << "Enter a string: ";
		getline (cin, mystring);
		cout << NoChar(badch, mystring) << endl;
	}
}
