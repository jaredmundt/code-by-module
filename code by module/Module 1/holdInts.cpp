// Uses a home-grown "vector" to illustrate memory management
#include <algorithm> // For copy
#include <cassert>
#include <cstddef>   // For size_t
#include <fstream>
#include <iostream>
using namespace std;

// Read ints from a file into an array
size_t readInts(const char* fileName, int*& nums) {
   // Initialize array
   enum {EXTENT = 10};
   nums = new int[EXTENT];
   size_t capacity = EXTENT;
   size_t numRead = 0;

   // Read numbers
   ifstream inf(fileName);
   if (inf) {
      int num;
      while (inf >> num) {
         if (numRead == capacity) {
            // Extend array
            cout << "Expanding array...\n";
            size_t new_capacity = capacity + EXTENT;
            int* newNums = new int[new_capacity];
            
            // Copy elements (could also use memcpy here)
            copy(nums,nums+numRead,newNums);

            // Delete old array
            delete [] nums;
            nums = newNums;
            capacity = new_capacity;
         }

         // Add new element
         assert(numRead < capacity);
         nums[numRead++] = num;
      }
   }

   cout << "capacity: "<< capacity << endl;
   return numRead;
}

int main(int argc, char* argv[]) {
   if (argc > 1) {
      int* nums;
      size_t nInts = readInts(argv[1], nums);
      cout << "Read " << nInts << " numbers\n";
      for (size_t i = 0; i < nInts; ++i)
         cout << nums[i] << ' ';
      cout << endl;
      delete [] nums;
   }
}

/* Output from the command: $ holdInts nums.dat:
Expanding array...
Expanding array...
capacity: 30
Read 21 numbers
5737 8716 5982 1804 6148 7004 5861 8292 3958 8948 3307 7194 1748 4800 1660 4131 8275 7370 9081 6934 3220 
*/