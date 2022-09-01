#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<class T,         template<class U,                  class = allocator<U> >
         class Seq>
void printSeq(Seq<T>& seq) {
  for(auto b = seq.begin();
       b != seq.end();)
    cout << *b++ << endl;
}

int main() {
  // Process a vector
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  printSeq(v);
  // Process a list
  list<int> lst;
  lst.push_back(3);
  lst.push_back(4);
  printSeq(lst);
}
