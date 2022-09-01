// Uses insert iterators to insert/append/prepend elements
#include <deque>	// Note: vector has no push_front() (front_inserter would fail)
#include <iostream>
#include <iterator>
using namespace std;

int main() {
	deque<int> v{1,2,5};	// New initialization syntax
	
	// Insert numbers at position 2:
	int middle[] = {3,4};
	copy(middle, middle+2, inserter(v,v.begin()+2));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout," "));
	cout << endl;
	
	// Append numbers
	int after[] = {6,7};
	copy(begin(after), end(after), back_inserter(v));
	copy(begin(v), end(v), ostream_iterator<int>(cout," "));
	cout << endl;
	
	// Prepend numbers
	int before[] = {0, -1};	// Note order
	copy(begin(before), end(before), front_inserter(v));
	copy(begin(v), end(v), ostream_iterator<int>(cout," "));
	cout << endl;
}

/* Output:
1 2 3 4 5 
1 2 3 4 5 6 7 
-1 0 1 2 3 4 5 6 7 
*/
