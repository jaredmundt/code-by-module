#include <iostream>
#include <vector>
using namespace std;


class Stuff {
	vector<int> data;
	mutable int last_idx;
public:
	Stuff() : last_idx(0) {}
  	void add(int x) {data.push_back(x);}
	int get(int pos) const {
		last_idx = pos;		// Modify a field in a const method
		return data.at(pos);
	}
	int last_accessed() const {return data[last_idx];}
};

int main() {
	Stuff s;
	s.add(1);
	s.add(2);
	cout << s.get(1) << endl;
	cout << s.last_accessed() << endl;
}
