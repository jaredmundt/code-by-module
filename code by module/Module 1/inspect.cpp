// inspect.cpp:   Inspect the bytes of an object
#include <cstddef>
#include <iostream>
#include <iomanip>
using namespace std;

void inspect(const void* ptr, size_t nbytes)
{
    const unsigned char* p =
	static_cast<const unsigned char*>(ptr);
	
	cout.setf(ios::hex, ios::basefield);
    for (size_t i = 0; i < nbytes; ++i)
        cout << "byte " << setw(2) << setfill(' ') << i
             << ":    " << setw(2) << setfill('0')
             << size_t(p[i]) << endl;
    cout.fill(' ');
}

int main()
{
    char c = 'a';
    short i = 100;
    long n = 100000L;
    double pi = 3.141529;
    char s[] = "hello";
    
    inspect(&c, sizeof c);   cout << endl;
    inspect(&i, sizeof i);   cout << endl;
    inspect(&n, sizeof n);   cout << endl;
    inspect(&pi, sizeof pi); cout << endl;
    inspect(s, sizeof s);    cout << endl;
}

/* Output:
byte  0:    61

byte  0:    64
byte  1:    00

byte  0:    a0
byte  1:    86
byte  2:    01
byte  3:    00
byte  4:    00
byte  5:    00
byte  6:    00
byte  7:    00

byte  0:    13
byte  1:    7c
byte  2:    d3
byte  3:    f4
byte  4:    d9
byte  5:    21
byte  6:    09
byte  7:    40

byte  0:    68
byte  1:    65
byte  2:    6c
byte  3:    6c
byte  4:    6f
byte  5:    00
*/