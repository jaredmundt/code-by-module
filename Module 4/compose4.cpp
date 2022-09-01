// compose4.cpp: Uses accumulate without reversing the sequence
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

using Fun = function<double(double)>;

class Composer {
private:
    vector<Fun>& funs;
public:
    Composer(vector<Fun>& fs) : funs(fs) {}
    double operator()(double x) const {
        auto apply = [](double sofar, Fun f){return f(sofar);};
        return accumulate(rbegin(funs),rend(funs),x,apply);
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
