// More fun with our template function
// Now we add a function object to flip
// one character to another
//
#include <iostream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

template <class T, class U>
T findci (T begin, T end, U c)
{
	while (begin != end) {
		if (*begin == c)
			break;
		++begin;
	}
	return begin;
}


class Flip
{
	char from, to;
public:
	Flip (char f, char t) : from(f), to(t) {}
	char operator() (char c) {
		if (c == from)
			return to;
		return c;
	}
};

int main()
{
	char c[] = "Now is the time for all good men";

	vector<char> vc;
	for (int i = 0; i < 26; i++)
		vc.push_back('a' + i);

	// Find the 'f'
	cout << *(findci (vc.begin(), vc.end(), 'f')) << endl;
	
	// Copy all from f to x
	copy (findci (vc.begin(), vc.end(), 'f'), findci (vc.begin(), vc.end(), 'x'),
	ostream_iterator<char>(cout, ", "));
	cout << endl;
	
	// Transform, changing the m to a Z
	vector<char> uvc;
	transform (findci (vc.begin(), vc.end(), 'f'), findci (vc.begin(), vc.end(), 'x'),
		back_inserter(uvc), Flip ('m', 'Z'));
		
	copy (uvc.begin(), uvc.end(), ostream_iterator<char>(cout, ", "));
	cout << endl;
	
	// Transform directly to cout, changing e to E
	transform (c, c+32, ostream_iterator<char>(cout, ""), Flip('e', 'E'));
	
	// Let the user pick
	char from, to;
	cout << "\n\nWhat character do you want to change? ";
	cin >> from;
	cout << "To what? ";
	cin >> to;
	
	transform (c, c+32, ostream_iterator<char>(cout, ""), Flip(from, to));
	
}



