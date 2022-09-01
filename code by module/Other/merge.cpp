// merge.cpp: Merge two sorted files to standard output
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>         // For EXIT codes
#include <cassert>
using namespace std;

int main(int argc, char *argv[]) {
    string line1, line2;

    // Open files:
    if (argc != 3)
        return EXIT_FAILURE;
    ifstream f1(argv[1]);
    ifstream f2(argv[2]);

    // Do the merge:
    getline(f1, line1);
    getline(f2, line2);
    while (f1 && f2) {
        // (INVARIANT: both lines have "fresh lines")

        // Print and refresh the appropriate line:
        if (line1 <= line2) {
            cout << line1 << endl;
            getline(f1, line1);
        } else {
            cout << line2 << endl;
            getline(f2, line2);
        }
    }

    // (INVARIANT: At least one file has been exhausted)
    assert(f1.eof() || f2.eof());

    // Empty the remaining file:
    while (f1) {
        // (INVARIANT: line1 has a fresh line)
        cout << line1 << endl;
        getline(f1, line1);
    }
    assert(f1.eof());     // (INVARIANT: file1 has been exhausted)

    while (f2) {
        // (INVARIANT: line2 has a fresh line)
        cout << line2 << endl;
        getline(f2, line2);
    }
    assert(f2.eof());     // (INVARIANT: file2 has been exhausted)

    return EXIT_SUCCESS;
}

