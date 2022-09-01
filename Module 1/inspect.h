// inspect.h: Displays the bytes of any object
#ifndef INSPECT_H
#define INSPECT_H

template<typename T>
void inspect(const T& t) {
   // Print bytes of t
   const unsigned char* p = reinterpret_cast<const unsigned char*>(&t);
   cout << hex;
   for (int i = 0; i < sizeof t; ++i)
      cout <<  size_t(p[i]) << ' ';
   cout << dec << endl;
}

#endif

