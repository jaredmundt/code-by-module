#include <iostream>
using namespace std;

template<bool>
struct StaticCheck {
   StaticCheck(...);
};

template<>
struct StaticCheck<false>{};

// The trick: Anything can be converted to a StaticCheck<bool>
//            Nothing can be converted to a StaticCheck<false>

#define STATIC_CHECK(expr, msg) {             \
   class Error_##msg{};                       \
   sizeof((StaticCheck<expr>(Error_##msg()))); \
}

// STATIC_CHECK tries to convert the class Error_##msg
// (whatever it turns out to be) to a StaticCheck<expr>.
// If expr is true, it's fine, otherwise you'll get a message
// like: "Can't convert Error_<whatever> to StaticCheck<0>"
// (because false == 0).

template<class To, class From>
To safe_cast(From from)
{
   STATIC_CHECK(sizeof(From) <= sizeof(To), NarrowingConversion);
   return reinterpret_cast<To>(from);
}

int main()
{
   void* p = 0;
   int i = safe_cast<int>(p);
   cout << "int cast okay\n";
   char c = safe_cast<char>(p);
}

