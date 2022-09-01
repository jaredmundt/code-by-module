#include <iostream>
#include <limits>  // For numeric_limits::max()
#include <string>
#include <sstream>

using namespace std;

bool isvowel(char ch) {
    char c = tolower(ch);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

class PigLat {
    string str;
public:
    PigLat (string s) : str(s) {}
    friend ostream& operator<<(ostream& os, const PigLat& n) {
        istringstream iss(n.str);
        string word;
        while (iss >> word) {
            char c = word[0];
            if (isalpha(c)) {
                if (isvowel(c)) {
                    os << word << "way ";
                } else {
                    unsigned int i{1};
                    for (;i < word.size() && !isvowel(word[i]); i++);
		    // Special case for "Qu"
		    if (tolower(word[i-1]) == 'q' && tolower(word[i]) == 'u')
			    i++;
                    os << word.substr(i) << word.substr(0,i) << "ay ";
                }
            } else {
                os << word << " ";
            }
        }
        return os;
    }
};

int main() {
char badch;
string mystring;

    while (true) {
        cout << "Enter a string: ";
        getline (cin, mystring);
        cout << PigLat(mystring) << endl;
    }
}
