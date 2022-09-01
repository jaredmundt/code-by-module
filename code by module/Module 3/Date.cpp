#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Date {
    unsigned short month;
    unsigned short day;
    unsigned short year;
public:
    Date(int m=0, int d=0, int y=0) {
        month = m;
        day = d;
        year = y;
    }
    friend ostream& operator<<(ostream& os, const Date& d) {
        return os << '{' << d.month << '-' << d.day << '-' << d.year << '}';
    }
    friend istream& operator>>(istream& is, Date& d) {
      is >> d.month;
      if (is) {
        char c{' '};
        is >> c;
        if(c != '-') {
          is.unget();
          is.setstate(ios::failbit);
        }
        is >> d.day;
        if (is) {
          c = ' ';
          is >> c;
          if(c != '-') {
            is.unget();
            is.setstate(ios::failbit);
          }
          is >> d.year;
        }
      }
      return is;
    }
};

void str_state(istream& is) {
    if (is.good())
        cout << " good";
    if (is.eof())
        cout << " eof";
    if (is.fail())
        cout << " fail";
    cout << endl;
}

int main() {
    Date d{7,17,2014};
    cout << d << endl;

    string s{"7-18-2014"};
    istringstream is(s);
    str_state(is);
    is >> d;
    cout << d << endl;
    str_state(is);

    is.str("7-19-2014");
    is.seekg(0);
    is >> d;
    cout << d << endl;
    str_state(is);

    // Error tests
    is.str("-19-2014");
    is.seekg(0);
    d = Date();
    string rest;
    is >> d;
    is.clear();
    is >> rest;
    cout << d << ' ' << rest << ' ' << endl;
    str_state(is);

    is.str("7/19/2014");
    is.seekg(0);
    d = Date();
    is >> d;
    cout << d << endl;
    is.clear();
    is >> rest;
    cout << d << ' ' << rest << ' ' << endl;
    str_state(is); 
}