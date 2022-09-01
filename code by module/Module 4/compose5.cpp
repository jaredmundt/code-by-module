// compose5.cpp: Makes the function type generic
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename Fun>
class Composer {
private:
    vector<Fun>& funs;
public:
    Composer(vector<Fun>& fs) : funs(fs) {}
    using T = typename Fun::result_type;
    T operator()(T x) const {
        auto apply = [](T sofar, Fun f){return f(sofar);};
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
    using Fun = function<double(double)>;
    vector<Fun> funs{f,g(),[](double x){return x+1;}};
    Composer<Fun> comp(funs);
    cout << comp(2.0) << endl;          // 4.5
    
    using Fun2 = function<string(const string&)>;
    vector<Fun2> funs2{[](const string& s){return s+"s";},[](const string& s){return s+"'";}};
    Composer<Fun2> comp2(funs2);
    cout << comp2("Vernor") << endl;    // Vernor's
}
