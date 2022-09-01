// cover.cpp: Illustrates Covariant return types

struct BaseRet {};
struct DerRet : BaseRet {};

struct Base
{
   virtual BaseRet* f() {return new BaseRet;}
};

struct Derived : Base
{
   DerRet* f() {return new DerRet;}
};
