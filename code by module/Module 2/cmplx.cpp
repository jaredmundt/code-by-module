#include <iostream>

class complex
{
    double real;
    double imag;

public:
    complex(double real = 0, double imag = 0)  // 3-in-1!
    {
        this->real = real;
        this->imag = imag;
    }
    complex add(const complex& c)
    {
        complex result;
        result.real = this->real + c.real;
        result.imag = this->imag + c.imag;
        return result;
    }
    void display(std::ostream& os)
    {
        os << '(' << real << ',' << imag << ")\n";
    }
};

int main()
{
    complex z(1.0,2.0), w(3.0);
    complex a = z.add(w);	// z + w
    a.display(std::cout);  // "(4.0,2.0)"
    complex b = z.add(1.0);	// z.add(complex(1.0));
    b.display(std::cout);  // "(2.0,2.0)"
}

