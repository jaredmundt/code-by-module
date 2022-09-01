// ambiguous2.cpp
class Base1 {
public:
   virtual void f(){}
};

class Base2  : public virtual Base1 {
public:
   void f(){}
};

class Base3 : public virtual Base1 {
public:
   void f(){}
};

class Derived : public Base2, public Base3 {};  // line 17

int main() {
   Derived d;
   d.f();           // line 21
}

/* Compiler Output:
ambiguous2.cpp:17:44: error: no unique final overrider for 'virtual void Base1::f()' in 'Derived'
ambiguous2.cpp: In function 'int main()':
ambiguous2.cpp:21:6: error: request for member 'f' is ambiguous
ambiguous2.cpp:14:9: error: candidates are: virtual void Base3::f()
ambiguous2.cpp:9:9: error:                 virtual void Base2::f()
*/
