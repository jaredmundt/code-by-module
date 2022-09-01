#include <iostream>
using namespace std;

class T {
public:
   T() {
      cout << "Default ctor\n";
   }
   ~T() {
      cout << "Destructor\n";
   }
};

int main() {
   T objs[10];
}

