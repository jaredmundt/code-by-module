#include <iostream>
#include <cstddef>
using namespace std;

int main() {
    int a[][3][4] {{{1,2,3,4},{5,6,7,8},{9,0,1,2}},
                   {{3,4,5,6},{7,8,9,0},{1,2,3,4}}};
    int (*p)[3][4] = a;
    cout << "sizeof(p): " << sizeof(p) << endl;
    cout << "sizeof(p[0]): " << sizeof(p[0]) << endl;
    cout << "sizeof(p[0][0]): " << sizeof(p[0][0]) << endl;
    size_t n = sizeof(a) / sizeof(a[0]);
    for (size_t i = 0; i < n; ++i) {
        cout << "sizeof(p[" << i << "]): " << sizeof(p[i]) << endl;
        size_t m = sizeof(a[i]) / sizeof(a[i][0]);
        for (size_t j = 0; j < m; ++j) {
            cout << "sizeof(" << p[i][j] << "): " << sizeof(p[i][j]) << endl;
            size_t t = sizeof(a[i][j]) / sizeof(a[i][0][0]);
            for (size_t k = 0; k < t; ++k)
                cout << "- sizeof(" << p[i][j][k] << "): " << sizeof(p[i][j][k]) << endl;
        }
    }
}
 
 /* Output:
sizeof(p): 8
sizeof(p[0]): 48
sizeof(p[0][0]): 16
sizeof(p[0]): 48
sizeof(0x7fff50bbfc00): 16
- sizeof(1): 4
- sizeof(2): 4
- sizeof(3): 4
- sizeof(4): 4
sizeof(0x7fff50bbfc10): 16
- sizeof(5): 4
- sizeof(6): 4
- sizeof(7): 4
- sizeof(8): 4
sizeof(0x7fff50bbfc20): 16
- sizeof(9): 4
- sizeof(0): 4
- sizeof(1): 4
- sizeof(2): 4
sizeof(p[1]): 48
sizeof(0x7fff50bbfc30): 16
- sizeof(3): 4
- sizeof(4): 4
- sizeof(5): 4
- sizeof(6): 4
sizeof(0x7fff50bbfc40): 16
- sizeof(7): 4
- sizeof(8): 4
- sizeof(9): 4
- sizeof(0): 4
sizeof(0x7fff50bbfc50): 16
- sizeof(1): 4
- sizeof(2): 4
- sizeof(3): 4
- sizeof(4): 4
 */       