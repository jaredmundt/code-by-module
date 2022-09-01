#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <fstream>

using namespace std;

int main() {
	vector<int> v {1,2,3,4,5,6,7,8 };
	vector<int> vc {v};

	vector<float> vf;

	copy (v.begin(), v.end(), ostream_iterator<int> (cout, " "));
	cout << endl;

	// Transform into a different vector
	// And putting them in backwards
	transform (v.begin(), v.end(), vc.rbegin(), [] (int x) { return x + (x/2);});
	copy (vc.begin(), vc.end(), ostream_iterator<int> (cout, " "));
	cout << endl << endl;

	// Transform into itself (careful!)
	transform (v.begin() + 1, v.end() -1, v.begin(), [] (int x) { return x * (x - 1); });
	copy (v.begin(), v.end(), ostream_iterator<int> (cout, " "));
	cout << endl << endl;

	// Transform using back_inserter
	// Also: lambda returns a different type
	// 
	float div = static_cast<float>(vc[0]);
	transform (v.begin(), v.end(), back_inserter(vf),
	       	[div] (int x)->float { return static_cast<float>(x)/div;});

	copy (vf.begin(), vf.end(), ostream_iterator<float> (cout, " "));
	cout << endl << endl;

	// Using Transform to read and transform file input in one step
	//
	vector<string> vw;
	ifstream inwords("fewwords.txt");

	transform (istream_iterator<string>(inwords), istream_iterator<string>(), back_inserter(vw), [] (string s) { return s + s; });
	copy (vw.begin(), vw.end(), ostream_iterator<string> (cout, " "));
	cout << endl;
}
