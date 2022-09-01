// Adapted from Williams, page 29
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>
using namespace std;

// Find number of hardware threads available
auto nthreads = thread::hardware_concurrency();
vector<double> results(nthreads);	// Place for threads to return results

using Iter = vector<double>::iterator;
void accum_block(Iter b, Iter e, size_t i) {
	results[i] = accumulate(b,e,0.0);
}

double concurrent_sum(Iter start, Iter stop) {
	vector<thread> threads(nthreads-1);	// Worker threads

	// Launch threads
	auto block_size = (stop - start) / nthreads;
	for (size_t i = 0; i < nthreads-1; ++i) {
		threads[i] = thread(accum_block,start+i*block_size,start+(i+1)*block_size,i);
	}

	// Sum last block here in main thread (could be bigger than block_size)
	double sum = accumulate(start+(nthreads-1)*block_size,stop,0.0);

	// Join other threads
	for (size_t i = 0; i < nthreads-1; ++i)
		threads[i].join();
	return accumulate(begin(results),end(results),sum);
}

int main() {
	vector<double> v;
	size_t n = 100000000;
	v.reserve(n);
	srand(time(nullptr));
	generate_n(back_inserter(v),n,[](){return rand()/1000.0;}); // populate

	// Sequential sum
	auto start = chrono::high_resolution_clock::now();
	cout << accumulate(begin(v),end(v),0.0) << endl;
	auto stop = chrono::high_resolution_clock::now();
	cout << chrono::duration<double>(stop - start).count() << endl;
	cout << endl;

	// Pause a little
	cout << "Sleeping..." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

	// Concurrent sum
	cout << "Number of threads: " << nthreads << endl;
	start = chrono::high_resolution_clock::now();
	cout << concurrent_sum(begin(v),end(v)) << endl;
	stop = chrono::high_resolution_clock::now();
	cout << chrono::duration<double>(stop - start).count() << endl;
}

/* Output:
Number of threads: 8
1.07381e+14
0.432328

1.07381e+14
0.131175
*/
