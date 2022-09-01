// compose1.cpp: Composes functions of doubles
#include <iostream>
#include <vector>
using namespace std;

using Fun = double (*)(double);

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

double g(double x) {
    return x*x;
}

double h(double x) {
    return x+1;
}

int main() {
    vector<Fun> funs{&f,&g,&h};
    Composer comp(funs);
    cout << comp(2.0) << endl;  // 4.5
}
