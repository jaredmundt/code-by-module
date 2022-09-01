#include <iostream>
using namespace std;

class Trace
{
    int x;

public:
    Trace(int x)
    {
        this->x = x;
        cout << "Trace(int): " << this->x << endl;
    }
    Trace(const Trace& t)
    {
        x = t.x;
        cout << "Trace(const Trace&): " << x << endl;
    }
    ~Trace()
    {
        cout << "~Trace(): " << x << endl;
    }
    friend Trace f(Trace t)
    {
        return t.x + 1;
    }
    friend Trace g(Trace t)
    {
        t.x += 1;
        return t;
    }
};

int main()
{
    cout << "Defining t1...\n";
    Trace t1 = 7;
    cout << "\nDefining t2...\n";
    Trace t2 = f(t1);
    cout << "\nDefining t3...\n";
    Trace t3 = g(t2); 
}

/* Output: (Illustrates return-value optimization)
Defining t1...
Trace(int): 7

Defining t2...
Trace(const Trace&): 7
Trace(int): 8
~Trace(): 7
<missing temporary here, due to RV optimization>

Defining t3...
Trace(const Trace&): 8
Trace(const Trace&): 9
~Trace(): 9
<missing temporary here, due to RV optimization>
~Trace(): 9
~Trace(): 8
~Trace(): 7
*/

