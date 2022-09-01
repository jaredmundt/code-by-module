// Simulates a 2-state FA that accepts an even number of 0's
// Illustrates std::function, recursive callables, lambdas with explicit return types,
#include <cctype>       // For isspace()
#include <cstdlib>      // For exit()
#include <functional>   // For function<>
#include <iostream>
#include <sstream>
using namespace std;

struct StateFn {
    function<StateFn*(istream&)> fn;
    StateFn* operator()(istream& is) {
        return fn(is);
    }
};

char getNextByte(istream& is) {
    char c = is.get();
    return isspace(c) ? getNextByte(is) : c;
}

StateFn state1;
StateFn state2;

auto f1 = [](istream& is)->StateFn* {
    auto c = getNextByte(is);
    if (c == -1) {
        cout << "accept\n";
        exit(0);
    }
    switch (c) {
        case '0':
            return &state2;
        case '1':
            return &state1;
        default:
            cout << "reject\n";
            return nullptr;
    }
};

auto f2 = [](istream& is)->StateFn* {
    auto c = getNextByte(is);
    if (c == -1) {
        cout << "reject\n";
        exit(0);
    }
    switch (c) {
        case '0':
            return &state1;
        case '1':
            return &state2;
        default:
            cout << "reject\n";
            return nullptr;
    }
};

int main() {
    state1.fn = f1;
    state2.fn = f2;
    StateFn* current_state = &state1;
    istringstream s("101000");
    while (current_state)
        current_state = (*current_state)(s);
}
