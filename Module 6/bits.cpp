#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <climits>
using namespace std;

class Bits
{
   unsigned int data;
   enum {NBITS = sizeof(unsigned int) * CHAR_BIT};
   friend class reference;

public:
   explicit Bits(unsigned int n = 0) : data(n) {}
   void set(size_t pos);
   void set();
   void reset(size_t pos);
   void reset();
   void flip(size_t pos);
   void flip();
   bool test(size_t pos) const;
   bool any() const;
   size_t count() const;
   size_t size() const;
   unsigned int extract(size_t m, size_t n) const;
   operator unsigned int () const {
       return data;
   }
   friend ostream& operator<<(ostream& os, const Bits& b);
   friend bool operator==(const Bits& b1, const Bits& b2);

    class reference {
        Bits& b;
        int pos;
    public:
        reference(Bits& bs, int p) : b(bs) {
            pos = p;
        }
        reference& operator=(bool bit) {
            // Set the bit in position pos to true or false, per "bit
            if (bit)
                b.data |= (1u << pos);
            else
                b.data &= ~(1u << pos);
            return *this;
        }
        operator bool () const {
            // Return true or false per the bit in position pos
            return b.data & (1u << pos);
        }
    };
   reference operator[](int pos) {
        return reference(*this, pos);
   }
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
