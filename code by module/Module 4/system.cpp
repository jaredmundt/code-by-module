#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
    system("ls *.cpp >files.dat 2>/dev/null");
    ifstream ifs{"files.dat"};
    copy(istream_iterator<string>{ifs},istream_iterator<string>(),
         ostream_iterator<string>(cout,"\n"));
    system("rm files.dat");
}