class Base1 {};
class Base2 : private Base1 {};


class Derived : public Base2
{};

int main()
{
   Derived d;
   Base1* pb1 = &d;
   Base2* pb2 = &d;
}

/* Output:
Error E2034 c:\uvsc\spring02\3370\indirect.cpp 11: Cannot convert 'Derived *' to 'Base1 *' in function main()
*/

