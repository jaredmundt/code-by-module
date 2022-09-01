// Uses an array of 2 integers as a fixed-size bit array
#include <cassert>
#include <climits>
#include <cstddef>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename IType = size_t, size_t NBLOCKS = 2>
class Bits
{
   enum {BITS_PER_WORD = sizeof(IType) * CHAR_BIT};
   IType data[NBLOCKS] = {0};
   int nused = 0;
   static size_t word_offset(size_t bitpos) {
     return bitpos/BITS_PER_WORD;
   }
   static size_t bit_offset(size_t bitpos) {
     return bitpos%BITS_PER_WORD;
   }
   static IType mask1(size_t bitpos) {
     return IType(1) << bit_offset(bitpos);
   }
   static IType mask0(size_t bitpos) {
     return ~mask1(bitpos);
   }


public:
   explicit Bits() = default;
   void set(size_t pos);
   void set();
   void reset(size_t pos);
   void reset();
   void toggle(size_t pos);
   void toggle();
   bool test(size_t pos) const;
   friend ostream& operator<<(ostream& os, const Bits& b);
};

void Bits::set(size_t pos)
{
   data |= (1u << pos);
}

void Bits::set()
{
   data = ~0u;
}

void Bits::reset(size_t pos)
{
   data &= ~(1u << pos);
}

void Bits::reset()
{
   data = 0;
}

void Bits::flip(size_t pos) {
    data ^= (1u << pos);
}

void Bits::flip() {
    data ^= ~0u;
}

bool Bits::test(size_t pos) const
{
   return data & (1u << pos);
}

bool Bits::any() const
{
   return data;
}

size_t Bits::count() const
{
   unsigned int d = data;
   unsigned int sum = 0;
   for (int i = 0; i < NBITS; ++i)
   {
      // Inspect least-significant bit; shift right
      sum += d&1;
      d >>= 1;
   }
   return sum;
}

size_t Bits::size() const
{
   return NBITS;
}

unsigned int Bits::extract(size_t m, size_t n) const {
    unsigned int mask = ~0u >> (NBITS - n + m - 1);
    return (data >> m) & mask;
}

ostream& operator<<(ostream& os, const Bits& b)
{
   for (int i = 0; i < b.size(); ++i)
      os << b.test(b.size() - i - 1);
   return os;
}

bool operator==(const Bits& b1, const Bits& b2)
{
   return b1.data == b2.data;
}

// The following function validates operator<<(ostream&, const Bits&)
bool compareStrings(const Bits& b, size_t pos)
{
   // Print the representation of b to a string
   ostringstream os;
   os << b;

   // Builds what the string representation of
   // a Bits object should be with only bit number
   // 'pos' set.
   size_t nbits = b.size();
   string bits(nbits, '0');
   bits[nbits - pos - 1] = '1';

   // Compare the two strings
   string s = os.str();
   return bits == s;
}

int main()
{
   Bits b;

   // b is empty:
   assert(!b.any());
   assert(!b.count());

   // b is full:
   b.set();
   assert(b.any());
   assert(b.count() == b.size());

   // b is empty again:
   b.reset();
   assert(!b.any());
   assert(!b.count());

   for (int i = 0; i < b.size(); ++i)
   {
      // Set each bit in turn(right-to-left)
      // then reset it:
      b.set(i);
      assert(b.test(i));
      assert(b.count() == 1);
      assert(compareStrings(b, i));

      b.reset(i);
      assert(!b.test(i));
      assert(b.count() == 0);
   }

   Bits a(100000);
   Bits c(a);
   c.flip();
   for (int i = 0; i < c.size(); ++i) {
       assert(a.test(i) == !c.test(i));
       c.flip(i);
   }
   assert(a == c);
   cout << "Tests successful\n";

   cout << c << endl;
   Bits d(c.extract(10,20));
   cout << d << endl;
   cout << d[0] << endl;
   cout << d[1] << endl;
   cout << d[5] << endl;
   d[5] = 0;
   cout << d[5] << endl;
   cout << static_cast<unsigned int>(d) << endl;
}

/* Output:
Tests successful
00000000000000011000011010100000
00000000000000000000000001100001
1
0
1
0
65
*/
