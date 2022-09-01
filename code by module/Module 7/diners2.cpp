// Dining Philosophers
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

constexpr int n = 4;
mutex chopsticks[n], print;

void phil(int pno, int left, int right) {
    for (auto i: {1,2,3}) {
        unique_lock<mutex> lock1(print);
        cout << "Philosopher " << pno << " is thinking" << endl;
        lock1.unlock();
        this_thread::sleep_for(chrono::milliseconds(300));

        // Time to eat
        unique_lock<mutex> lock2(chopsticks[left],defer_lock);
        unique_lock<mutex> lock3(chopsticks[right],defer_lock);
        lock(lock1,lock2,lock3);
        cout << "Philosopher " << pno << " is eating with chopsticks "
             << left << " and " << right << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main() {
    thread p[n];
    for (int i = 0; i < n; ++i)
        p[i] = thread(phil,i,i,(i+1)%n);    // move assignment
    for (int i = 0; i < n; ++i)
        p[i].join();
}