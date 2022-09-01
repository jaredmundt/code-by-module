#include <iostream>
#include <limits>  // For numeric_limits::max()
#include <string>
using namespace std;

// Put out a prefix of a string:
class Fixw {
  string str;
public:
  Fixw(const string& s, int width) : str(s) {
      str.resize(width,' ');  // The space is in case you grow the result
  }
  friend ostream& operator<<(ostream& os, const Fixw& fw) {
    return os << fw.str;
  }
};

class Bin {
  uint32_t n;
public:
  Bin(uint32_t nn) { n = nn; }
  friend ostream& operator<<(ostream& os, const Bin& b) {
    auto UMAX = numeric_limits<uint32_t>::max();
    auto bit = ~(UMAX >> 1); // Top bit set
    while(bit) {
      os << (b.n & bit ? '1' : '0');
      bit >>= 1;
    }
    return os;
  }
};

int main() {
  string words = "Things that make us happy, make us wise";
  for (size_t i = words.size(); i > 0; --i)
    cout << Fixw(words, i) << endl;
  cout << '"' << Fixw(words,50) << "\"\n";
  
  cout << Bin(0xCAFEBABE) << endl;
  cout << Bin(0x76543210) << endl;
}

/* Output:
Things that make us happy, make us wis
Things that make us happy, make us wi
Things that make us happy, make us w
Things that make us happy, make us 
Things that make us happy, make us
Things that make us happy, make u
Things that make us happy, make 
Things that make us happy, make
Things that make us happy, mak
Things that make us happy, ma
Things that make us happy, m
Things that make us happy, 
Things that make us happy,
Things that make us happy
Things that make us happ
Things that make us hap
Things that make us ha
Things that make us h
Things that make us 
Things that make us
Things that make u
Things that make 
Things that make
Things that mak
Things that ma
Things that m
Things that 
Things that
Things tha
Things th
Things t
Things 
Things
Thing
Thin
Thi
Th
T
"Things that make us happy, make us wise           "
11001010111111101011101010111110
01110110010101000011001000010000
*/