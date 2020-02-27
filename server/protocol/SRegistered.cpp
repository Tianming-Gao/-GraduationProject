#include <string>
#include "IMProtocol.cpp"
using namespace std;

class CRegistered : public IMProtocol {
    public:
        string result;      // 0 = 成功     1 = 账号已经存在
        int type;           // 0 = 测试玩家  1 = 正式玩家
};