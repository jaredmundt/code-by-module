enum {rows = 3, cols = 3};
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
      for (int j = 0; j < cols; j+=3)
        y[i] += a[i][j]*x[j] + a[i][j+1]*x[j+1] + a[i][j+2]*x[j+2];
  }
}
int main() {
  int a[rows][cols], x[cols], y[cols];
  init_a(a);
  init_x(x);
  mult(a, x, y);
}
