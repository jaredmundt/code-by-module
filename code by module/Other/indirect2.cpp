#include <iostream>
using namespace std;

int main() {
	int i = 1, j = 2;
	int* p = &i;
	int* q = &j;

	i = j;
	*p = j;
	*p = *q;
	cout << i << endl;	// 2

	i = 1;
	int** p2 = &p;
	int** q2 = &q;
	*q2 = *p2;
	cout << **q2 << endl;	// 1

	char a[10]{"hello"};
	char b[10]{"goodbye"};
	char* s = a;	// Same as &a[0] because of pointer decay
	char* t = b;	// Same as &b[0] because of pointer decay
	cout << s << endl;	// hello
	cout << t << endl;  // goodbye
	s = t;
	cout << s << endl;	// goodbye

	s = a;	// Restore s to point to a
	char** s2 = &s;
	char** t2 = &t;
	*t2 = *s2;	// Same as t = s;
	cout << t << endl;	// hello
}
