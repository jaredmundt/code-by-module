//upcast.cpp: Shows access errors with non-public bases
class Base1 {};
class Base2 {};
class Base3 {};

class Derived : public Base1, protected Base2, private Base3
{};

class MoreDerived : public Derived {
    void f() {
       Base1* pb1 = this;
       Base2* pb2 = this;
       Base3* pb3 = this;   // line 13
    }
};

int main()
{
   Derived d;
   Base1* pb1 = &d;
   Base2* pb2 = &d;         // line 21   
   Base3* pb3 = &d;         // line 22
}

/* Compiler output:
upcast.cpp: In member function 'void MoreDerived::f()':
upcast.cpp:13:15: error: within this context
upcast.cpp:13:21: error: 'Base3' is an inaccessible base of 'MoreDerived'
upcast.cpp: In function 'int main()':
upcast.cpp:21:18: error: 'Base2' is an inaccessible base of 'Derived'
upcast.cpp:22:18: error: 'Base3' is an inaccessible base of 'Derived'
*/
