#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string data("1 two 3.2");
    istringstream istr(data);
    int n;
    string s;
    double x;
    istr >> n >> s >> x;
    cout << "data:\n";
    cout << "\tint: " << n << endl;
    cout << "\tstring: " << s << endl;
    cout << "\tdouble: " << x << endl;
    
    ostringstream ostr;
    ostr << n << ' ' << s << ' ' << x;
    cout << "Putting it all together: " << ostr.str() << endl;
}

/* Output:
data:
	int: 1
	string: two
	double: 3
Putting it all together: 1 two 3
*/
