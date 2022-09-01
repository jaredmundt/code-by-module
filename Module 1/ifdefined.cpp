#include <iostream>
#include <string>
using namespace std;

#if defined _MSCVER
const string id = "Visual Studio";
#elif defined __GNUC__
const string id = "GCC";
#else
const string id = "unknown";
#endif

int main() {
    cout << id << '\n';
}