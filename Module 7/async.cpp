// async.cpp: No global results vector needed
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <iterator>
#include <numeric>
#include <future>
#include <vector>
using namespace std;

// Find number of hardware threads available
auto nthreads = thread::hardware_concurrency();

using Iter = vector<double>::iterator;
double accum_block(Iter b, Iter e, size_t i) {
	return accumulate(b,e,0.0);
}

double concurrent_sum(Iter start, Iter stop) {
	vector<future<double>> tasks(nthreads-1);	// Worker tasks

	// Launch tasks
	auto block_size = (stop - start) / nthreads;
	for (size_t i = 0; i < nthreads-1; ++i) {
		tasks[i] = async(launch::async,accum_block,start+i*block_size,start+(i+1)*block_size,i);
	}

	// Sum last block
	double sum = accumulate(start+(nthreads-1)*block_size,stop,0.0);

	// Wait for tasks
	for (size_t i = 0; i < nthreads-1; ++i)
		sum += tasks[i].get();
	return sum;
}

int main() {
	cout << "Number of threads: " << nthreads << endl;
	vector<double> v;
	size_t n = 100000000;
	v.reserve(n);
	generate_n(back_inserter(v),n,[](){return rand()/1000.0;});

	auto start = chrono::high_resolution_clock::now();
	cout << accumulate(begin(v),end(v),0.0) << endl;
	auto stop = chrono::high_resolution_clock::now();
	cout << chrono::duration<double>(stop - start).count() << endl;
	cout << endl;

	start = chrono::high_resolution_clock::now();
	cout << concurrent_sum(begin(v),end(v)) << endl;
	stop = chrono::high_resolution_clock::now();
	cout << chrono::duration<double>(stop - start).count() << endl;
}
