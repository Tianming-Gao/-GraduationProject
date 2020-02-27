#include "../include/NetWorker.h"

class Global {
    public:
        NetWorker* NT;
    public:
        Global() {

        }
        ~Global() {

        }

        bool InitAllInstances();
};

bool Global::InitAllInstances() {
    NT = new NetWorker;
    return true;
}