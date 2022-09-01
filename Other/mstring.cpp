// A moveable string class

#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class String {
    char* data;
public:
    String(const char* p = "") {
        cout << "1-arg ctor: " << p << endl;
        strcpy(data=new char[strlen(p)+1],p);
    }
    String(const String& s) : String(s.data) {  // Delegating ctor
        cout << "copy ctor: " << s.data << endl;
    }
    String(String&& s) : data(move(s.data)) {   // Steal resources (move only really necessary with class types)
        cout << "move ctor: " << data << endl;
        s.data = nullptr;                       // Zero-out temporary
    }
    String& operator=(const String& s) {
        cout << "copy assignment: " << s.data << endl;
        if (this != &s) {
            char* new_data = new char[strlen(s.data)+1];
            strcpy(new_data,s.data);
            delete [] data;
            data = new_data;
        }
        return *this;
    }
    String& operator=(String&& s) {
        cout << "move assignment: " << s.data << endl;
        std::swap(data,s.data);                 // Steal resources via swapping
        return *this;
    }
    ~String() {
        cout << "destroying: " << (data ? data : "nullptr") << endl;
        delete [] data;
    }
    friend void print(const vector<String>&);
};

void print(const vector<String>& v) {
    cout << "<print>\n";
    for (const auto& x: v)
        cout << x.data << endl;
    cout << "</print>\n";
}

int main() {
    String s{"hello"};
    vector<String> v;
    v.reserve(3);
    v.push_back("every");        // Thanks Kevin
    v.push_back(String("little"));
    v.emplace_back(String("thing"));
    cout << v.size() << endl;
    print(v);
}

/* Output:
1-arg ctor: hello
1-arg ctor: every
move ctor: every
destroying: nullptr
1-arg ctor: little
move ctor: little
destroying: nullptr
1-arg ctor: thing
move ctor: thing
destroying: nullptr
3
<print>
every
little
thing
</print>
destroying: every
destroying: little
destroying: thing
destroying: hello
*/
