#include <fstream>
#include <iostream>
using namespace std;

#define D(strm,exp) strm << exp << " (" << #exp << ')' << endl

int main() {
    ofstream fil("format.out");
    int i = 47;
    double f = 2300114.414159;
    const char* s = "Is there any more?";

    fil.setf(ios::unitbuf);     // auto-flush
    fil.setf(ios::showbase);    // precede with 0 for octal and 0x for hex
    fil.setf(ios::uppercase | ios::showpos);    // 0X for hex, show +/-
    D(fil,i);
    fil.setf(ios::hex, ios::basefield);         // << hex
    D(fil,i);
    fil.setf(ios::oct, ios::basefield);         // << oct
    D(fil,i);
    fil.unsetf(ios::showbase);
    fil.setf(ios::dec, ios::basefield);         // << dec
    fil.setf(ios::left, ios::adjustfield);      // << left
    fil.fill('0');                              // << setfill('0')
    D(fil,"fill char: " << fil.fill());
    fil.width(10);                              // << setw(10)
    D(fil,i);
    fil.setf(ios::right, ios::adjustfield);     // right
    fil.width(10);
    D(fil,i);
    fil.setf(ios::internal, ios::adjustfield);  // internal
    fil.width(10);
    D(fil,i);
    D(fil,i); // Without width(10)
    fil << endl;

    fil.unsetf(ios::showpos);                   // << noshowpos
    fil.setf(ios::showpoint);                   // << showpoint
    D(fil,"prec = " << fil.precision());
    fil.setf(ios::scientific, ios::floatfield); // << scientific
    D(fil,f);
    fil.unsetf(ios::uppercase);                 // << uppercase
    D(fil,f);
    fil.setf(ios::fixed, ios::floatfield);      // << fixed
    D(fil,f);
    fil.precision(20);                          // << setprecision(20)
    D(fil,"prec = " << fil.precision());        
    D(fil,f);
    fil.setf(ios::scientific, ios::floatfield);
    D(fil,f);
    fil.setf(ios::fixed, ios::floatfield);
    D(fil,f);
    fil << endl;

    fil.width(10);                              // << setw(10)
    D(fil,s);
    fil.width(40);
    D(fil,s);
    fil.setf(ios::left, ios::adjustfield);
    fil.width(40);
    D(fil,s);
}
