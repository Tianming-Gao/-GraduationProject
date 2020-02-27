#include <string>
#include "IMProtocol.cpp"
using namespace std;

class SLogin : public IMProtocol {
    public:
        string account;
        string os; // TODO:android or pc
        string userTpye;
        string nickname;
        string result; // 0 = success, 1 = failed
};