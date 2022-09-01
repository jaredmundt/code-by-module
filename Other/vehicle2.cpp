// vehicle2.cpp: uses type_info::name()
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// An Abstract Class
class Vehicle {
protected:
    const string id;
public:
    Vehicle(const string& theID) : id(theID) {}
    virtual ~Vehicle() = default;
    virtual void stop() = 0;
    virtual void go() = 0;
    string type() const {
        return typeid(*this).name();
    }
};

class Automobile : public Vehicle {
public:
    Automobile(const string & theID) : Vehicle(theID) {}
    void go() override {
        cout << id << ": Giddyap, giddyap, 409\n";
    }
    void stop() override {
        cout << id << ": Stepping on brake\n";
    }
};

class Airplane : public Vehicle {
public:
    Airplane(const string & theID) : Vehicle(theID) {}
    void go() override {
        cout << id << ": Off we go, into the Wild Blue Yonder...\n";
    }
    void stop() override {
        cout << id << ": We are starting our descent into Salt Lake City...\n";
    }
};

void test(Vehicle* p) {
    cout << "Testing a " << p->type() << ":\n";
    p->go();
    p->stop();
}

int main() {
    Automobile a("ABC123");
    Airplane p("CNT99");
    Vehicle* v[] = {&a, &p};
    for (const auto p: v)
        test(p);
        
    Automobile* pa = dynamic_cast<Automobile*>(v[1]);
    if (pa)
        cout << "It's an Automobile\n";
    Airplane* pp = dynamic_cast<Airplane*>(v[1]);
    if (pp)
        cout << "It's an Airplane\n";
}        

/* Output:
Testing a 10Automobile:
ABC123: Giddyap, giddyap, 409
ABC123: Stepping on brake
Testing a 8Airplane:
CNT99: Off we go, into the Wild Blue Yonder...
CNT99: We are starting our descent into Salt Lake City...
It's an Airplane
*/