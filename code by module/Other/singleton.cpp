class Singleton
{
   static Singleton* theInstance;
   Singleton(){}
public:
   static Singleton* getInstance()
   {
      if (theInstance == 0)
         theInstance = new Singleton;
      return theInstance;
   }
};

Singleton* Singleton::theInstance = 0;

int main()
{
   Singleton* aSingleton = Singleton::getInstance();
}

