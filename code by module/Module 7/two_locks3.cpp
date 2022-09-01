// Illustrates std::lock and adopt_lock
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx1,mtx2;

void john() {
    for (auto i: {1,2,3}) {
        lock(mtx1,mtx2);
        lock_guard<mutex> lock1(mtx1,adopt_lock);
        lock_guard<mutex> lock2(mtx2,adopt_lock);
        cout << "John has the locks" << endl;
    }
}

void jane() {
    for (auto i: {1,2,3}) {
        lock(mtx1,mtx2);
        lock_guard<mutex> lock1(mtx1,adopt_lock);
        lock_guard<mutex> lock2(mtx2,adopt_lock);
        cout << "Jane has the locks" << endl;
    }
}

int main() {
    auto t1 = thread(john);
    auto t2 = thread(jane);
    t1.join();
    t2.join();
}