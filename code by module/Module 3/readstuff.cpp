#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

int main()
{
   int theInt1 = 0, theInt2 = 0;
   do
   {
      string line;
      cout << "Enter two ints between 1 and 5: ";
      getline(cin, line);
      if (!cin)               // Check for ^Z/^D (unlikely)
         break;
      istringstream is(line);
      if (!(is >> theInt1 >> theInt2))    // Check for bad characters entered
         continue;
   } while (theInt1 < 1 || theInt1 > 5 || theInt2 < 1 || theInt2 > 5);
   cout << "You entered " << theInt1 << ',' << theInt2 << endl;
}
