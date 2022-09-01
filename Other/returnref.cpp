// returnref.cpp: Investigates return by reference
#include <iostream>
#include <string>
using namespace std;

class Data;

class Ref {     // Acts like a reference
    Data* pData;
public:
    Ref(Data* d) : pData(d) {}
    void operator=(const Data& d);  // unusual return type!
    operator Data() const;          // implicit conversion to Data
};

class Data {
    int x;
    string y;
    friend class Ref;   // grant private access for Ref to Data's state
public:
    Data(int eks, const string& why) : y(why) {
        x = eks;
    }
    Ref ref() {
        return Ref(this);
    }
    void display() const {
        cout << '(' << x << ',' << y << ")\n";
    }
};

void Ref::operator=(const Data& d) {
    cout << "Ref::operator=\n";
    pData->x = d.x;
    pData->y = d.y;
}

Ref::operator Data() const {
    cout << "Ref::operator Data\n";
    return *pData;
}

int main() {
    Data d(4,"four");
    d.display();        // (4,four)
    Data d2(5,"five");
    d2.display();       // (5,five)
    Ref r = d.ref();
    r = d2;             // operator=
    d.display();        // (5,five)
    Data d3(6,"six");
    d3.display();       // (6,six)
    d3 = r;             // operator Data
    d3.display();       // (5,five)
}

/* Output:
(4,four)
(5,five)
operator=
(5,five)
(6,six)
operator Data
(5,five)
*/