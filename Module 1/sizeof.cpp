#include <iostream>
#include <cstddef>
using namespace std;

int main() {
    int a[][3] {{1,2,3},{4,5,6},{7,8,9}};
    cout << "sizeof(a): " << sizeof(a) << endl;
    size_t n = sizeof(a) / sizeof(a[0]);
    for (size_t i = 0; i < n; ++i) {
        cout << "sizeof(a[" << i << "]): " << sizeof(a[i]) << endl;
        size_t m = sizeof(a[i]) / sizeof(int);
        for (size_t j = 0; j < m; ++j)
            cout << "sizeof(" << a[i][j] << "): " << sizeof(a[i][j]) << endl;
    }
}
 
 /* Output:
 sizeof(a): 36
 sizeof(a[0]): 12
 sizeof(1): 4
 sizeof(2): 4
 sizeof(3): 4
 sizeof(a[1]): 12
 sizeof(4): 4
 sizeof(5): 4
 sizeof(6): 4
 sizeof(a[2]): 12
 sizeof(7): 4
 sizeof(8): 4
 sizeof(9): 4
 */       