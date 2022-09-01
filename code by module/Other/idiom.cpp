#include <iostream>
using namespace std;

class Subject;

class Proxy
{
   friend class Subject;
   Subject& subj;
   int pos;
   Proxy(Subject& subj, int pos) : subj(subj)
   {
      this->pos = pos;
   }
public:
   operator int() const;
   Proxy& operator=(int);
   Proxy& operator=(const Proxy& p)
   {
      return operator=(int(p));
   }
};


class Subject
{
   friend class Proxy;
   enum {MAX_ELEMS = 10};
   int data[MAX_ELEMS];
public:
   Proxy operator[](size_t pos)
   {
      return Proxy(*this, pos);
   }
   int get(size_t pos)
   {
      if (pos >= MAX_ELEMS)
         throw logic_error("index out of range");
      return data[pos];
   }
   void set(size_t pos, int x)
   {
      if (pos >= MAX_ELEMS)
         throw logic_error("index out of range");
      data[pos] = x;
   }
};

Proxy::operator int() const
{
   cout << "RHS(" << pos << ")\n";
   return subj.get(pos);
}

Proxy& Proxy::operator=(int b)
{
   cout << "LHS(" << pos << ")\n";
   subj.set(pos, b);
   return *this;
}
            
int main()
{
   // Initialize a subject
   Subject s;
   s.set(0, 10);
   s.set(1, 20);
   s.set(2, 30);

   int i = s[0];
   s[1] = i;
   s[3] = s[2];
   cout << s.get(0) << endl;
   cout << s.get(1) << endl;
   cout << s.get(2) << endl;
   cout << s.get(3) << endl;
}

/* Output:
RHS(0)
LHS(1)
RHS(2)
LHS(3)
10
10
30
30
*/

