// compose3.cpp: Reverses the sequence to enable range-based for loop. Uses a lambda expresison.
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

using Fun = function<double(double)>;

class Composer {
private:
    vector<Fun> funs;   // Copied this time (no &)
public:
    Composer(vector<Fun>& fs) : funs(fs) {
        reverse(funs.begin(),funs.end());
    }
    double operator()(double x) const {
        double result = x;
        for (auto p: funs)
            result = p(result); // p is not a function ptr now
        return result;
    }
};

// A function object type
struct g {
    double operator()(double x) {
        return x*x;
    }
};

int main() {
    auto f = [](double x){return x/2.0;};
    vector<Fun> funs{f,g(),[](double x){return x+1;}};
    Composer comp(funs);
    cout << comp(2.0) << endl;  // 4.5
}
