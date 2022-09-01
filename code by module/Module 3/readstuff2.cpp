// How NOT to get user input
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
   int theInt = 0;
   do
   {
      cout << "Enter an int between 1 and 5: ";
      cin >> theInt;    // Infinite loop on ^Z/^D
      if (!cin)
         cin.clear();   // Doesn't work on cin when ^Z/^D has been entered!
   } while (theInt < 1 || theInt > 5);
   cout << "You entered " << theInt << endl;
}
