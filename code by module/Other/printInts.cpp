// Shows how to easily read ints from a file into a container
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc > 1) {
		ifstream f(argv[1]);
		if (f) {
			copy(istream_iterator<int>{f},istream_iterator<int>{},ostream_iterator<int>{cout, " "});
			cout << endl;
		}
	}
}