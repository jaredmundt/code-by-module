struct C
{
   ~C(){}
};

void g();	// for all we know, g may throw

void f()
{
   C c;	// Destructor must be called
   g();
}
