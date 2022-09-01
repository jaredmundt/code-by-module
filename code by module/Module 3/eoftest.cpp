#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream ifs("eoftest.cpp");
    string line;
    while (getline(ifs, line)) {
        cout << ifs.eof() << ifs.fail() << ifs.good() << ": \"" << line << "\"\n";
    }
    cout << ifs.eof() << ifs.fail() << ifs.good() << '\n';
}
