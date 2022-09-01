// remove algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove
#include <vector>
#include <iterator>
using namespace std;

int main () {
  string s = "Now is the time";
  cout << s.size() << endl;

  remove (begin(s), end(s), 't');
  cout << s.size() << endl;
  cout << s << endl << endl;
  
  vector<int> v{10, 15,20, 10, 20, 15, 20, 15};
  vector<int> v2 (v.begin(), v.end());
  cout << v.size() << endl;
  auto vend = remove (begin(v), end(v), 20);
  cout << v.size() << endl;
  copy (begin(v), end(v), ostream_iterator<int>(cout, " "));
  cout << endl;
  
  // correct:
  v2.erase(remove(begin(v2), end(v2), 20), end(v2));
  cout << v2.size() << endl;
  copy (begin(v2), end(v2), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
