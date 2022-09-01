#include <cstring>
#include <iostream>

class String
{
    char* data;

public:
    String(const char* s = "")
    {
        data = new char[std::strlen(s) + 1];
        std::strcpy(data,s);
    }
    ~String() {delete [] data;}
    int size() const {return std::strlen(data);}
    char getAt(int pos) const {return data[pos];}
    void setAt(int pos, char c) const {data[pos] = c;}
    void display()
    {
        std::cout << data;
    }
};

int main()
{
   String s = "hello";
   String t = s;		// same as String t(s);
   t.setAt(0,'j');
   s.display();
}
