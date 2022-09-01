// Iterator Evolution, step 2:
//  Creating a template function
//
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;



class CharIter
{
	char* b;
public:
	CharIter(char* c) : b(c) {}
	bool operator!=(const CharIter& rhs) const {
		return (b != rhs.b);
	}
	char operator*() { return *b; }
	CharIter operator++() { ++b; return *this; }
};

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

int main()
{
	char c[] = "Now is the time for all good men";

	CharIter cx = findci (CharIter(c), CharIter(c+32), 'e');
	cout << *cx << endl;
	
	// Using the function template with a vector
	vector<char> vc;
	for (int i = 0; i < 26; i++)
		vc.push_back('a' + i);
	cout << *(findci (vc.begin(), vc.end(), 'f')) << endl;
	
	// Copy all letters from f until x
	copy (findci (vc.begin(), vc.end(), 'f'), findci (vc.begin(), vc.end(), 'x'),
	ostream_iterator<char>(cout, ", "));
}


