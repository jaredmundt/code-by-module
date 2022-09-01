#include <cassert>
#include <cstddef>
#include <iostream>
#include <list>
using namespace std;

class IntStack : private list<int> { // Never inherit publicly from value types
public:
    void push(int i) {
        push_front(i);
    }
    void pop() {
        pop_front();
    }
    int top() const {
        return front();
    }
    size_t size() const {
        return list<int>::size();
    }
};

int main() {
    // Populate
    IntStack stk;
    for (int i = 0; i < 10; ++i)
        stk.push(i);
    assert(stk.size() == 10);
    
    // Empty the stack
    while (stk.size() > 0) {
        cout << stk.top() << endl;
        stk.pop();
    }
    assert(stk.size() == 0);
    
    // Try to use a list method
    // stk.pop_back();  // error!
}

/* Output:
9
8
7
6
5
4
3
2
1
0
*/

/* Compile error text:
stack-private-list.cpp: In function ‘int main()’:
/usr/include/c++/4.0.0/bits/stl_list.h:787: error: ‘void std::list<_Tp, _Alloc>::pop_back() [with _Tp = int, _Alloc = std::allocator<int>]’ is inaccessible
stack-private-list.cpp:38: error: within this context
stack-private-list.cpp:38: error: ‘std::list<int, std::allocator<int> >’ is not an accessible base of ‘IntStack’
*/