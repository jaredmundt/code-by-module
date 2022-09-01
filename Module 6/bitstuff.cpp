#include <bitset>
#include <iomanip>
#include <iostream>
using namespace std;

using IType = unsigned char;

#define display(x) cout << setw(10) << #x << ": " << bitset<8>(x) << endl

bool read(IType n, unsigned int pos) {
    IType mask = IType(1) << pos;
    return mask & n;
}

IType set(IType n, unsigned int pos) {
    IType mask = IType(1) << pos;
    return mask | n;
}

IType reset(IType n, IType pos) {
    IType mask = IType(1) << pos;
    return ~mask & n;
}

IType flip(IType n, IType pos) {
    IType mask = IType(1) << pos;
    return mask ^ n;
}

IType extract(IType n, unsigned int hi, unsigned int lo) {
    IType mask = (IType(1) << (hi - lo + 1)) - 1;
    return (n >> lo) & mask;
}

IType copybit(IType n, unsigned int pos) {
    IType res = n;
    if (read(n,pos))
        set(res,pos);
    else
        reset(res,pos);
    return res;
}

int main() {
    IType n = 0b01001101, m = 0b11100011;
    display(n);
    display(~n);
    display(m);
    display(n >> 2);
    display(m << 3);
    display(m | n);
    display(m & n);
    display(m ^ n);
    display(read(n,5));
    display(read(m,5));
    display(set(n,5)) << endl;
    display(reset(m,5)) << endl;
    display(flip(n,4)) << endl;

    // Illustrate sign extension
    signed char k = 0b11100011;
    display(int(k));
    display(k >> 4); 
    auto x = extract(m,6,4);
    display(int(x)); 
    display(x);
}

/*  Output:
         n: 01001101
        ~n: 10110010
         m: 11100011
    n >> 2: 00010011
    m << 3: 00011000
     m | n: 11101111
     m & n: 01000001
     m ^ n: 10101110
 read(n,5): 00000000
 read(m,5): 00000001
  set(n,5): 01101101

reset(m,5): 11000011

 flip(n,4): 01011101

    int(k): 11100011
    k >> 4: 11111110
    int(x): 00000110
         x: 00000110
*/
