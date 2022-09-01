#include <iostream>
using namespace std;

template<class T>
class Box;

template<class T>
ostream& operator<<(ostream&, const Box<T>&);

template<class T>
class Box {
   T t;
public:
   Box(const T& t) : t(t){}
   friend ostream& operator<< <> (ostream& os, const Box<T>& b);
};


template<class T>
ostream& operator<<(ostream& os, const Box<T>& b) {
   return os << b.t;
}

int main() {
   Box<int> b(2);
   cout << b << endl;
}

