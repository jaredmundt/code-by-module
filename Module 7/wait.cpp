 // Note: Condition variables must use unique_locks
#include <condition_variable>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

queue<int> q;
condition_variable q_cond;
mutex q_sync, print;

void consumer() {
    while (true) {
        unique_lock<mutex> qlck(q_sync);
        q_cond.wait(qlck,[](){return !q.empty();});
        auto x = q.front();
        q.pop();
        qlck.unlock();
        if (x < 0)
            break;
        lock_guard<mutex> plck(print);
        cout << x << " consumed" << endl;
    }
}

void producer() {
    srand(time(nullptr));
    for (int i = 0; i < 20; ++i) {
        int n = rand();
        unique_lock<mutex> qlck(q_sync);
        q.push(n);
        qlck.unlock();
        q_cond.notify_one();    // Always unlock before notifying
        lock_guard<mutex> plck(print);
        cout << n << " produced" << endl;
    }
    unique_lock<mutex> lck(q_sync);
    q.push(-1);
    lck.unlock();
    q_cond.notify_one();
}

int main() {
    auto t1 = thread(consumer);
    auto t2 = thread(producer);
    t2.join();
    t1.join();
}