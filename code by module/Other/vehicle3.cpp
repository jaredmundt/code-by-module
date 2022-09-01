// vehicle2.cpp: Illustrates dynamic_cast
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

class Glider : public Airplane {
public:
    Glider(const string & theID) : Airplane(theID) {}
    void go() override {
        cout << id << ": Flying away on a wing and a prayer...\n";
    }
    void stop() override {
        cout << id << ": I can't control this thing!\n";
    }
};

int main() {
    Automobile a("ABC123");
    Airplane p("CNT99");
    Glider g("Ralph");
    Vehicle* v[] = {&a, &p, &g};
    
    // Dynamic cast tests
    for (const auto p: v) {
        cout << p->type() << ": ";
        if (dynamic_cast<Vehicle*>(p))
            cout << "A vehicle";
        if (dynamic_cast<Automobile*>(p))
            cout << ", and an automobile";
        if (dynamic_cast<Airplane*>(p))
            cout << ", and an airplane";
        if (dynamic_cast<Glider*>(p))
            cout << ", and a glider";
        cout << endl;
    }
}        

/* Output:
10Automobile: A vehicle, and an automobile
8Airplane: A vehicle, and an airplane
6Glider: A vehicle, and an airplane, and a glider
*/