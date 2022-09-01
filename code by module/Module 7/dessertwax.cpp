#include <iostream>
#include <thread>
using namespace std;

void f(const string & s) {
    for (int i=0; i < 10; ++i) {
        for (char c: s)
        	cout << c;
        cout << '\n';
    }
}

int main() {
    thread t1{f,"It's a Dessert Topping"};
    thread t2{f,"It's a Floor Wax"};
    t1.join();
    t2.join();
}

/* Output:
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
It's a Floor WIt's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
It's a Dessert Topping
ax
It's a Floor Wax
It's a Floor Wax
It's a Floor Wax
*/
