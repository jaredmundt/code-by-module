#include <iostream>
using namespace std;

int main()
{
    float a[] = {1.0, 2.0, 3.0};

    cout << "sizeof(float) == " << sizeof(float) << endl;
    float* p = &a[0];	// or just a;
    cout << "p == " << p << ", *p == " << *p << endl;
    ++p;
    cout << "p == " << p << ", *p == " << *p << endl;
    
    // Subtract two pointers:
    ptrdiff_t diff = (p+1) - p;
    cout << "diff == " << diff << endl;
    diff = reinterpret_cast<char*>(p+1) -
           reinterpret_cast<char*>(p);
    cout << "diff == " << diff << endl;
}

/* Output:
sizeof(float) == 4
p == 0x7fff5fbff8f0, *p == 1
p == 0x7fff5fbff8f4, *p == 2
diff == 1
diff == 4
*/