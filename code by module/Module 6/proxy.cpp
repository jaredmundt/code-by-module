#include <iostream>
using namespace std;

class BitArray {
public:
    struct bitproxy {
        operator bool() const {
            cout << "bitproxy::operator bool\n";
            return true;
        }
        void operator=(bool) {
            cout << "bitproxy::operator=\n"; 
        } 
    };
    bitproxy operator[](size_t) {
        return bitproxy();
    }
};

int main() {
    BitArray b;
    bool x = b[5];
    b[5] = false;
}