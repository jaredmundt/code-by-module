#include <iostream>
using namespace std;

template<int v>
struct Int2Type
{
   enum {val = v};
};

// Int2Type<n> is a distinct type for each distinct n.

template<class T, bool isPolymorphic>
class MyClass
{
   void doSomething(T* obj, Int2Type<true>)
   {
      cout << "doing something polymorphic with " << *obj << endl;
   }
   void doSomething(T* obj, Int2Type<false>)
   {
      cout << "doing something non-polymorphic with " << *obj << endl;
   }
public:
   void doSomething(T* obj)
   {
      doSomething(obj, Int2Type<isPolymorphic>());
   }
};

int main()
{
   int i = 1;
   MyClass<int, true> m1;
   m1.doSomething(&i);
   MyClass<int, false> m2;
   m2.doSomething(&i);
}


