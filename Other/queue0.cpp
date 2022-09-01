// This is a static solution. Uses the implicit STL
// interface for sequences.

#include <cstdio>
#include <deque>
#include <iostream>
#include <list>
using namespace std;

template<typename T, class Impl = deque<T> >
class Queue {
public:
    Queue() = default;
   void add(const T&);
   T get() const;
   void remove();
   int size() const;
   void clear();
private:
   Impl impl;
   Queue(const Queue&) = delete;
   Queue& operator=(const Queue&) = delete;
};
   
template<typename T, class Impl>
void Queue<T, Impl>::add(const T& t) {
   impl.push_front(t);
}

template<typename T, class Impl>
T Queue<T, Impl>::get() const {
   return impl.back();
}

template<typename T, class Impl>
void Queue<T, Impl>::remove() {
   impl.pop_back();
}

template<typename T, class Impl>
int Queue<T, Impl>::size() const {
   return impl.size();
}

template<typename T, class Impl>
void Queue<T, Impl>::clear() {
   impl.clear();
}

int main() {
   // Do ints
   Queue<int> q;
   for (int i = 0; i < 10; ++i)
      q.add(i);

   while (q.size() > 0) {
      cout << q.get() << ' ';
      q.remove();
   }
   cout << endl;

   // Do strings
   Queue<string, list<string> > q2;
   for (int i = 0; i < 10; ++i) {
      char buf[3];
      sprintf(buf,"%d",i);
      q2.add(buf);
   }

   while (q2.size() > 0) {
      cout << q2.get() << ' ';
      q2.remove();
   }
   cout << endl;
}

/* Output:
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
*/
