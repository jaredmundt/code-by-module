#include <iostream>
#include <string>
using namespace std;

string next_token(const string&, int&);
string bad_chars = "`1234567890-=~!@#$%^&*()_+[]"
                   "\\{}|;':\",./<>?\t\v\a\n";

int main()
{
    string s = "1one2 two #three@!!";
    int pos = 0;
    string token;
    while (!(token = next_token(s,pos)).empty())
        cout << '"' << token << '"' << endl;
}
string next_token(const string& s, int& pos)
{
    int begin = 
        s.find_first_not_of(bad_chars,pos);
    int end = s.find_first_of(bad_chars,begin);
    pos = end;
    if (begin == string::npos)
        return string("");
    else if (end == string::npos)
        return s.substr(begin);
    else
        return s.substr(begin, end-begin);
}

