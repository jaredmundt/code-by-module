#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ostringstream buf;
    ifstream inf("prepend.cpp");
    buf << inf.rdbuf();
    string stuff = buf.str();
    stuff.insert(0, "// prepend.cpp\n");
    ofstream outf("prepend.out");
    outf << stuff;
}
