// Uses the streambuf* ostream overload to output an entire file
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream in("rdbuf1.cpp");
    cout << in.rdbuf();     // Outputs entire file
}
