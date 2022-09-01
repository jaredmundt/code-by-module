#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <ctime>
#include <stdexcept>
using namespace std;

class Logfile
{
   ofstream theFile;    

   Logfile()                     // Constructor is private
   {
      theFile.open("myLog.txt");
      if (!theFile)
         throw runtime_error("error opening log file");
   }
   static string getTime()
   {
      time_t tval = time(0);
      string timeString(ctime(&tval));
      timeString.resize(timeString.size()-1);   // drop '\n'
      return timeString;
   }

   // Disable inadvertent copying
   Logfile(const Logfile&);
   Logfile& operator=(const Logfile&);

public:
   // Accessor to singleton
   static Logfile& getInstance()
   {
      static Logfile theInstance;
      return theInstance;
   }
   void addEntry(const string& s)
   {
      theFile << getTime() << ": " << s << endl;
   }
   ~Logfile()
   {
      theFile.close();
   }
};

void f()
{
   Logfile& pLog = Logfile::getInstance();
   pLog.addEntry("A log entry from f");
}

void g()
{
   Logfile& pLog = Logfile::getInstance();
   pLog.addEntry("A log entry from g");
}

void delay()
{
   unsigned long spin_cycle = numeric_limits<unsigned long>::max() / 3;
   for (unsigned long i = 0; i < spin_cycle; ++i)
      ;
}

int main()
{
   f();
   delay();
   g();
}

