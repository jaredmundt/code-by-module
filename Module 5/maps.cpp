#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

class Debugger {
public:
  string value;
  Debugger() {
    value = "uninitialized";
    cout << "Initializing (default)" << endl;
  }
  Debugger(const string& v) : value(v) {
    cout << "Initializing (" << v << ")" << endl;
  }
  Debugger(const Debugger& o) : value(o.value) {
    cout << "Copying (" << value << ")" << endl;
  }
  Debugger(Debugger&& o) : value(std::move(o.value)) {
    cout << "Moving (" << value << ")" << endl;
  }
  Debugger& operator= (const Debugger& o) {
    cout << "Assigning (Debugger " << o.value << ")" << endl;
    value = o.value;
    return *this;
  }
  Debugger& operator= (const string& s) {
    cout << "Assigning (string " << s << ")" << endl;
    value = s;
    return *this;
  }
  ~Debugger() {
    cout << "Destroying (" << value << ")" << endl;
  }
  friend ostream& operator<< (ostream& os, const Debugger& d) {
    os << "Debugger(" << d.value << ")";
    return os;
  }
};

int main() {
  auto comp = [](Debugger x, Debugger y){return x.value < y.value;};
  map<Debugger, Debugger, decltype(comp)> m_sq(comp);
  map<Debugger, Debugger, decltype(comp)> m_at(comp);

  Debugger a("a");
  Debugger b("b");
  Debugger c("c");
  Debugger d("d");
  Debugger e("e");
  Debugger f("f");

  cout << endl << "a and b ([])" << endl;
  m_sq[a] = b;

  cout << endl << "a and b (insert)" << endl;
  m_at.insert({a, b});

  cout << endl << "c and d ([])" << endl;
  m_sq[c] = d;

  cout << endl << "c and d (insert)" << endl;
  m_at.insert({c, d});

  cout << endl << "e and f ([])" << endl;
  m_sq[e] = f;

  cout << endl << "e and f (insert)" << endl;
  m_at.insert({e, f});

  cout << endl << "output ([])" << endl;
  for (auto it = m_sq.cbegin(); it != m_sq.cend(); ++it) {
    cout << it->first << ", " << it->second << endl;
  }

  cout << endl << "output (insert)" << endl;
  for (auto it = m_at.cbegin(); it != m_at.cend(); ++it) {
    cout << it->first << ", " << it->second << endl;
  }

  cout << endl << "cleanup" << endl;
  return 0;
}
