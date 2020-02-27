#include <string>
#include "IMProtocol.cpp"
using namespace std;

class CLogin : public IMProtocol {
    public:
        string email;
        string type; // 0 = player, 1 = tester, 2 = reconnect
        string version; // client version
        string account;
        string passwd;
        string sessionToken; // TODO
};