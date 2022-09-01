// Dining Philosophers
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

enum {n = 4};
mutex chopsticks[n], print;

void phil(int pno, int left, int right) {
    for (auto i: {1,2,3}) {
        unique_lock<mutex> lock1(print);    // Lock the "print" mutex
        cout << "Philosopher " << pno << " is thinking" << endl;
        lock1.unlock();
        this_thread::sleep_for(chrono::milliseconds(300));

        // Time to eat
        lock(chopsticks[left],chopsticks[right],lock1); // Lock all 3 mutexes
        lock_guard<mutex> lock2(chopsticks[left],adopt_lock);
        lock_guard<mutex> lock3(chopsticks[right],adopt_lock);
        cout << "Philosopher " << pno << " is eating with chopsticks "
             << left << " and " << right << endl;
        lock1.unlock(); // Release print lock
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main() {
    thread p[n];
    for (int i = 0; i < n; ++i)
        p[i] = thread(phil,i,i,(i+1)%n);    // move assignment!
    for (int i = 0; i < n; ++i)
        p[i].join();
}