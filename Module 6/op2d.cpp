// Illustrates "operator[][]"
#include <iostream>
#include <cstddef>
using namespace std;

class Container
{
  enum {ROWS = 2, COLUMNS = 3};
  int data[ROWS][COLUMNS];
public:
  typedef int (*RowType)[COLUMNS];
  typedef const int (* ConstRowType)[COLUMNS];
  Container()
  {
    // Initialize array
    for (int i = 0; i < ROWS; ++i)
      for (int j = 0; j < COLUMNS; ++j)
        data[i][j] = i+j;
  }
  size_t rows() const
  {
    return ROWS;
  }
  size_t cols() const
  {
    return COLUMNS;
  }
  RowType& operator[](size_t row)
  {
    return data + row;
  }
  ConstRowType& operator[](size_t row) const
  {
    return data + row;
  }
};

void display(const Container& c)
{
  for (size_t i = 0; i < c.rows(); ++i)
  {
    for (size_t j = 0; j < c.cols(); ++j)
      cout << c[i][j] << ' ';
  
    cout << endl;
  }
}

int main()
{
  Container c;
  display(c);
//  c[1][2] = 100;
  display(c);
}

