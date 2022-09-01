#include <iostream>
#include <string>
using namespace std;


class Zero {
	int z;
public:
	Zero (int i) : z(i) {}

	string str ()  const {
		if (z)	return "non-zero";
		return "zero";
		// or: return (z) ? "non-zero" : "zero";
	}
	friend ostream& operator<< (ostream& os, const Zero& n) {
		os << n.str();
		return os;
	}
};

int main() {

	int i;

	while (true) {
		cout << "Enter a number: ";
		cin >> i;
		// Zero zee(i);
		cout << Zero(i) << endl;
	}
}
