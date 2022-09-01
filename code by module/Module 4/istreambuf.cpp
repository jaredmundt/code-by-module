#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main()
{
  ifstream ifs("istreambuf.cpp");
  string data((istreambuf_iterator<char>(ifs)),
              istreambuf_iterator<char>());
  cout << data << endl;
}

