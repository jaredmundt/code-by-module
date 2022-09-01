// compose2.cpp: Uses std::function to accommodate any callable
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

using Fun = function<double(double)>;

class Composer {
private:
    vector<Fun>& funs;
public:
    Composer(vector<Fun>& fs) : funs(fs) {}
    double operator()(double x) const {
        double result = x;
        for (auto p = funs.rbegin(); p != funs.rend(); ++p)
            result = (*p)(result);
        return result;
    }
};

double f(double x) {
    return x/2.0;
}

// A function object type
struct g {
    double operator()(double x) {
        return x*x;
    }
};

int main() {
    vector<Fun> funs{f,g(),[](double x){return x+1;}};
    Composer comp(funs);
    cout << comp(2.0) << endl;  // 4.5
}
