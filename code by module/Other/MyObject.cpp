// Illustrates static members
#include <iostream>

class MyObject
{
   int id;
   static int count;
public:
   MyObject(int id)
   {
      this->id = id;
      ++count;
   }
   MyObject(const MyObject& o)
   {
      this->id = o.id;
      ++count;
   }
   ~MyObject() {--count;}
   int getID() const {return id;}
   static int getCount() {return count;}
};

int MyObject::count = 0;

int main()
{
   using namespace std;
   cout << "There are now " << MyObject::getCount() << " objects\n";
   MyObject obj1(1);

   {
      MyObject obj2(2);
      MyObject obj3(obj2);
      cout << "There are now " << MyObject::getCount() << " objects\n";
   }
   cout << "There are now " << MyObject::getCount() << " objects\n";
}

/* Output:
There are now 0 objects
There are now 3 objects
There are now 1 objects
*/

