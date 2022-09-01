#include <iostream>
#include <string>

int main()
{
   std::string s = "hello";
   std::cout << s;
   // Calls std::operator<<(ostream&, const string&);
}

