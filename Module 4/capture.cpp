#include <iostream>
#include <functional>
using namespace std;

function<int(int)> addx(int x) {
    return [x](int y)->int {return x+y;};
}

int main() {
    auto f = addx(10);
    cout << f(3) << endl;	// 13
}
