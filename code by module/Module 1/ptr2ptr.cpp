#include <iostream>
using namespace std;

int main()
{
    int   i = 7;
    int*  ip = &i;
    int** ipp = &ip;

    cout << "Address " << ip << " contains " << *ip
         << endl;
    cout << "Address " << ipp << " contains " << *ipp
         << endl;
    cout << "**ipp == " << **ipp << endl;
}
