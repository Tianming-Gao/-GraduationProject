#include <string>
#include "IMProtocol.cpp"
using namespace std;

class CRegistered : public IMProtocol {
    public:
        string account;
        string password;
        string nickname;
        string userType;    // Default:"player" = player ,"tester" = tester
        string email;
};