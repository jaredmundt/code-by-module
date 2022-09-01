// Show noexcept

struct C
{
   ~C(){}
};

void g() noexcept;

void f()
{
   C c;	// Destructor must be called
   g();
}
