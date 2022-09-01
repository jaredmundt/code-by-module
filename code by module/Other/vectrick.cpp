#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename Iter1, typename Iter2, typename Fun>
void transform2(Iter1 b, Iter1 e, Iter2 d, Fun f) {
	while (b != e)
		*d++ = f(*b++);
}

int main() {
    auto filter = [](const int& x) {    // Returns void
        const int* iter = &x;
        for (int n: {0,1,2,3,4})
        	cout << iter[n] << endl;
    };

    vector<int> v{1,2,3,4,5};
    filter(v[0]);
    cout << endl;
    transform2(begin(v),end(v),ostream_iterator<int>(cout,"\n"),[](int n){return n+1;});
    cout << endl;
}
    