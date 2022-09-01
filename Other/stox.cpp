#include <iostream>
#include <string>
using namespace std;

template<typename T>
void inspect(T t) {
	cout << t << " (" << typeid(t).name() << ")\n";
}

int main() {
	size_t pos;
	inspect(stoi("123abc"));			// 123 (i)
	inspect(stoi("123abc",nullptr,4));	// 27 (i)
	inspect(stoi("123abc",&pos));		// 123 (i)
	cout << pos << endl;				// 3
	inspect(stol("123abc"));			// 123 (l)
	inspect(stoll("123abc"));			// 123 (x)
	inspect(stoul("123abc"));			// 123 (m)
	inspect(stoull("123abc"));			// 123 (y)

	inspect(stof("123.456"));			// 123.456 (f)
	inspect(stod("123.456"));			// 123.456 (d)
	inspect(stold("123.456"));			// 123.456 (e)
}

/* Visual Studio Output:
123 (int)
27 (int)
123 (int)
3
123 (long)
123 (__int64)
123 (unsigned long)
123 (unsigned __int64)
123.456 (float)
123.456 (double)
123.456 (long double)
*/