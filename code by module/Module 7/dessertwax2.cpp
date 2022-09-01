#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex m;

void f(const string & s) {
    for (int i=0; i < 10; ++i) {
    	m.lock();
        for (char c: s)
        	cout << c;
        cout << '\n';
        m.unlock();
    }
}

int main() {
    thread t1{f,"It's a Dessert Topping"};
    thread t2{f,"It's a Floor Wax"};
    t1.join();
    t2.join();
}

/* Output:
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
*/
