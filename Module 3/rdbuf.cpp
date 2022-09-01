#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
  ifstream ifs("rdbuf.cpp");
  ostringstream os;
  os << ifs.rdbuf();
  cout << os.str();
}

