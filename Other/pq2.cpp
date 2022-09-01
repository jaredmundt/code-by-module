// pq2.cpp: Illustrate priority_queue

// NOTE: Here we use greater<string> so the lesser strings come first.

#include <functional>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string words[] = {"these","are","the","times","that","try","men's","souls"};
    priority_queue<string,vector<string>,greater<string>> p;
    
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

/* Outut:
are
the
these

men's
souls
that
times
try
*/
