#include <ctime>
#include <iostream>
using namespace std;

enum {rows = 12000, cols = 12000};
void init_a(int a[rows][cols]) {
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      a[i][j] = i+j;
}
void init_x(int x[cols]) {
  for (int i = 0; i < cols; ++i)
    x[i] = i+1;
}
void mult(int a[rows][cols], int x[cols], int y[cols]) {
  for (int i = 0; i < rows; ++i) {
      y[i] = 0;
      for (int j = 0; j < cols; ++j)
        y[i] += a[i][j]*x[j];
  }
}
int main() {
  int (*a)[cols] = new int[rows][cols];
  int *x = new int[cols], *y = new int[cols];
  clock_t start = clock();
  init_a(a);
  init_x(x);
  mult(a, x, y);
  clock_t end = clock();
  cout << "duration: " << (end - start)/double(CLOCKS_PER_SEC) << endl;
  delete [] a;
  delete [] x;
  delete [] y;
}
