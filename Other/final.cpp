#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
using namespace std;
using namespace std::placeholders;

template<class T>
struct seqLen : unary_function<T, size_t>
{
   size_t operator()(const T& t)
   {
      return t.size();
   }
};

template<class T>
void display(T* begin, T* end, ostream& os)
{
   copy(begin, end, ostream_iterator<T>(os, " "));
   os << endl;
}

bool len3(const string& s)
{
   return s.size() > 3;
}

int main()
{
   string words[] = {"not", "by", "a", "long", "shot"};
   const size_t n = sizeof words / sizeof words[0];
   int a[n];
   transform(words, words + n, a, seqLen<string>());
   display(a, a+n, cout);
   cout << count_if(a, a+n, bind(greater<>(), _1, 3)) << endl;
   cout << count_if(words, words+n, len3) << endl;
}

/* Output:
3 2 1 4 4
2
2
*/

