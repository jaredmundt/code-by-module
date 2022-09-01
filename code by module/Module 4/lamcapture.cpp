#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums { 1,3,5,7,9,11,13,15};
	string prefix = "The number: ";

	// captures prefix, no need to capture globals, including cout or endl
	for_each(nums.begin(), nums.end(),
	    [prefix](int x) {cout << prefix << x << endl;});
	cout << endl;

	// Captures by reference, declares a return type
	string prefix2 = "Number.";
	for_each(nums.begin(), nums.end(),
	    [&prefix2] (int x)->void {cout << prefix2 << x << endl; prefix2 += ".";});
	cout << endl;

	// Captures all (by value)
	for_each(nums.begin(), nums.end(),
	    [=] (int x) { cout << (x % 3 ? prefix : prefix2) << x << endl;});
}

/* Output:
The number: 1
The number: 3
The number: 5
The number: 7
The number: 9
The number: 11
The number: 13
The number: 15

Number.1
Number..3
Number...5
Number....7
Number.....9
Number......11
Number.......13
Number........15

The number: 1
Number.........3
The number: 5
The number: 7
Number.........9
The number: 11
The number: 13
Number.........15
*/