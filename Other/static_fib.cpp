#include <iostream>
using namespace std;

int fibonacci() {
	static int current = 0;
	static int next = 1;
	
	int result = current;
	int temp = next;
	next = current + next; 
	current = temp;
	return result;
}

int main() {
	for (int i = 0; i < 5; ++i)
		cout << fibonacci() << endl;
}