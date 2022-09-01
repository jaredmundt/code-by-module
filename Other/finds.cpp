// Evolution of an iterator:
// Searching a sequence
//
#include <iostream>
using namespace std;

// One search function
// Pass in the size
char* findc (char* begin, int size, char c)
{
	int i = 0;
	for (;i < size; i++)
	{
		if (*begin == c)
			break;
		++begin;
	}
	return begin;
}

// Another search function: 
// pass in the begin and end pointers
char* findcc (char* begin, char* end, char c)
{
	while (begin != end) {
		if (*begin == c)
			break;
		++begin;
	}
	return begin;
}

// An iterator across a sequence of characters
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

// Search function using the character iterator
CharIter findci (CharIter begin, CharIter end, char c)
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

	char *cc = findc (c, 32, 'e');
	cout << cc << endl;
	cc = findcc (c, c + 32, 'e');
	cout << cc << endl;
	CharIter cx = findci (CharIter(c), CharIter(c+32), 'e');
	cout << *cx << endl;
}


