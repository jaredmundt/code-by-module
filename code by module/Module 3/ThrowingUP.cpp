//
// Shows difference between catching by reference and by value
//

#include <iostream>
using namespace std;

// Simple exception class
// Overloaded copy constructor to make copies visible
class Up
{
public:
	Up () {cout << "Creating Up\n"; }
	Up (const Up&) { cout << "	Copying Up\n"; }
	~Up () {cout << "		Up going away\n"; }
};

void fun()
{
	cout << "Having fun, throwing up\n";
	throw Up();
}

// Functions that catch and rethrow -- by value and by reference
void more_fun()
{
	cout << "Having more fun:\n";
	try {
		fun();
	} catch (Up p) {
		cout << "Catching up from fun\n";
		throw;
	}
}

void more_ref_fun()
{
	cout << "Having more fun:\n";
	try {
		fun();
	} catch (Up& p) {
		cout << "Catching up by reference from fun\n";
		throw;
	}
}

int main()
{
	try {
		fun();
	} catch (Up p) {
		cout << "Caught up by value\n";
	}
	cout << "\nLet's try again:\n\n";
	
	try {
		fun();
	} catch (Up& p) {
		cout << "Caught up by reference\n";
	}
	
	
	// Now we call the functions that rethrow
	// How many times is Up copied?
	cout << "\nLet's have more fun!\n\n";
	try {
	more_fun();
	} catch (Up p) {
		cout << "More value fun\n";
	}
	
	cout << "\n\n More fun by reference:\n";
	try {
		more_ref_fun();
	} catch (Up& p) {
		cout << "More reference fun\n";
	}
};

