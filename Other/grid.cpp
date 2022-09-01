// grid.cpp: Stores an x-y graph in a grid of chars
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

namespace
{
   const int xmax = 15;    	// # of columns
   const int ymax = xmax;  	// # of rows

   inline double f(double x) {
      // NOTE: Contrived to fix within grid!
      return x * x / ymax + 1.0;
   }
}

int main() {
    // Draw y-axis and clear 1st quadrant
    string blank_row(xmax, ' ');
    blank_row[0] = '|';
    vector<string> grid;
    fill_n(back_inserter(grid), ymax, blank_row);

    // Draw x-axis:
    grid[0][0] = '+';
    fill(grid[0].begin()+1, grid[0].end(), '-');

    // Populate with points (x, f(x))
    for (int x = 0; x < xmax; ++x)
        grid[f(x)][x] = '*';	// Remember: it's row-oriented

    copy(grid.rbegin(), grid.rend(), ostream_iterator<string>(cout, "\n"));
}

