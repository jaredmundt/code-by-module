// permutations.cpp: Considers all permutations of a string to find valid words
#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        // Load dictionary
        unordered_set<string> words;
        ifstream ifs("words.txt");
        string word;
        while (ifs >> word)
            words.insert(word);

        // Search for each permutation in dictionary
        string letters(argv[1]);
        sort(begin(letters),end(letters));
        do {
            if (words.find(letters) != words.end())
                cout << letters << endl;
        } while (next_permutation(begin(letters),end(letters)));
    }
}

/* Sample run:
$ ./a.out bruise
bruise
buries
busier
rubies
*/