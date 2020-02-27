#ifndef _NETWORK_H
#define _NETWORK_H

// 单例
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <strings.h>
#include <string>
#include <iostream>
using namespace std;

class NetWorker {
    public:
        NetWorker();
        ~NetWorker();
    private:
        bool Initialize();
        bool RpcAsync(int socketFd, char* payload, int size);
        void AddFd(int epollFd, int fd);
    protected:

};

#endif