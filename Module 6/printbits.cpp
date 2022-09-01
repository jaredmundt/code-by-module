#include <iostream>
#include <climits>
using namespace std;

template<typename IType>
void printbits(IType n) {
	auto nbits = sizeof(IType)*CHAR_BIT;
	auto mask = IType(1) << (nbits-1);
	while (mask) {
		cout << !!(n & mask);
		mask >>= 1;
	}
	cout << endl;
}

int main() {
	unsigned short x = 0xf0f0, y = 1;
	printbits(x);
	printbits(y);
	
	union overlay {
		unsigned char bytes[2];
		unsigned short n;
	};
	overlay z;
	z.n = y;
	cout << hex;
	for (int i = 0; i < 2; ++i) {
		unsigned int b = static_cast<unsigned int>(z.bytes[i]);
		cout << b << ' ';
	}
	cout << endl;
}

/* Output:
1111000011110000
0000000000000001
1 0 
*/