#include <iostream>
using namespace std;

int main() {
    int a[][3] {{1,2,3},{4,5,6},{7,8,9}};
    for (const auto &row: a) {
        cout << "sizeof(row): " << sizeof(row) << endl;
        for (const auto x: row)
            cout << "sizeof(" << x << "): " << sizeof(x) << endl;
    }
}
 
 /* Output:
 sizeof(row): 12
 sizeof(1): 4
 sizeof(2): 4
 sizeof(3): 4
 sizeof(row): 12
 sizeof(4): 4
 sizeof(5): 4
 sizeof(6): 4
 sizeof(row): 12
 sizeof(7): 4
 sizeof(8): 4
 sizeof(9): 4
 */       