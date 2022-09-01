// Illustrates sharing 2 resources "correctly" (but not exception safe!)
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx1,mtx2;

void john() {
    for (auto i: {1,2,3}) {
        mtx1.lock();
        this_thread::sleep_for(chrono::milliseconds(300));
        mtx2.lock();
        cout << "John has the locks" << endl;
        mtx2.unlock();
        mtx1.unlock();
    }
}

void jane() {
    for (auto i: {1,2,3}) {
        mtx1.lock();
        mtx2.lock();
        cout << "Jane has the locks" << endl;
        mtx2.unlock();
        mtx1.unlock();
    }
}

int main() {
    auto t1 = thread(john);
    auto t2 = thread(jane);
    t1.join();
    t2.join();
}