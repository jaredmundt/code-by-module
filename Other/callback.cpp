#include <iostream>
#include <string>
using namespace std;

class Callback
{
public:
   virtual void callback(const string&) = 0;
};

class Server
{
   Callback* client;
public:
   void attach(Callback* c)
   {
      client = c;
   }
   bool request(const string req)
   {
      cout << "Processing request " << req << "...\n";
      // Do stuff, then...
      notifyClient("request in progress");
      notifyClient("request in progress");

      return true;
   }
   void notifyClient(const string& s)
   {
      client->callback(s);
   }
};

class MyClient : public Callback
{
   Server* server;
public:
   MyClient(Server* server)
   {
      this->server = server;
   }
   void callback(const string& msg)
   {
      cout << "Client received message from server: " << msg << endl;
   }
   void run()
   {
      server->attach(this);
      server->request("foo");
      server->request("bar");
   }
};

int main()
{
   Server* s = new Server;
   MyClient* c = new MyClient(s);
   c->run();
}

/* Output:
Processing request foo...
Client received message from server: request in progress
Client received message from server: request in progress
Processing request bar...
Client received message from server: request in progress
Client received message from server: request in progress
*/

