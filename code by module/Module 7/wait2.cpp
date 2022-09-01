// 2 producers and consumers
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <ctime>
using namespace std;

queue<int> q;
condition_variable q_cond;
mutex q_sync, print, prod;
int nprod = 2;

void consumer() {
    for (;;) {
        // Get lock for queue
        unique_lock<mutex> qlck(q_sync);

        // Check for end of program (no live producers, no data left)
        {
            lock_guard<mutex> plck(prod);
            if (nprod == 0 && q.empty())
                break;
        }
        // Wait for queue to have something to process
        q_cond.wait(qlck,[](){return !q.empty();});
        auto x = q.front();
        q.pop();
        qlck.unlock();

        // Print trace of consumption
        lock_guard<mutex> plck(print);
        cout << x << " consumed" << endl;
    }
}

void producer(int i) {
    // Generate 20 random ints
    srand(time(nullptr)+i*(i+1));
    for (int i = 0; i < 20; ++i) {
        int n = rand();     // Get random int

        // Get lock for sync mutex; push int
        unique_lock<mutex> slck(q_sync);
        q.push(n);
        slck.unlock();
        q_cond.notify_one();

        // Get lock for print mutex
        lock_guard<mutex> plck(print);
        cout << n << " produced" << endl;
    }

    // Notify consumers that a producer has shut down
    lock_guard<mutex> lck(prod);
    --nprod;
    q_cond.notify_all();
}

int main() {
    auto c1 = thread(consumer);
    auto c2 = thread(consumer);
    auto p1 = thread(producer,0);
    auto p2 = thread(producer,1);
    p1.join();
    p2.join();
    c1.join();
    c2.join();
}