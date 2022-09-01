// static_assert.cpp
#include <climits>
static_assert(CHAR_BIT == 8,"8 bits per byte required");
static_assert(sizeof(char*) == 4,"32-bit architecture required");

const int N = 10;

void f() {
	static_assert(N > 2,"N must be > 2");
	int a[N];
}

/* Output on 32-bit machine:
/Users/chuck/UVU/3370/CourseCode/static_assert.cpp:4:1: error: static assertion failed: "32-bit architecture required"
*/
