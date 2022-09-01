// pq.cpp: Illustrate priority_queue

// NOTE: Priority queues use less<T> as their default comparator type,
// so "p" below uses less<string>(). Therefore, the greater strings are 
// higher in priority and are fetched first.

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string words[] = {"these","are","the","times","that","try","men's","souls"};
    priority_queue<string> p;
    
    // Insert the first four
    for (int i = 0; i < 4; ++i)
        p.push(words[i]);
        
    // Retrieve three
    for (int i = 0; i < 3; ++i) {
        cout << p.top() << endl;
        p.pop();
    }
    cout << endl;
    
    // Insert the rest
    for (int i = 4; i < 8; ++i)
        p.push(words[i]);
    
    // Retrieve the rest
    while (p.size() > 0) {
        cout << p.top() << endl;
        p.pop();
    }
}

/* Output:
times
these
the

try
that
souls
men's
are
*/
