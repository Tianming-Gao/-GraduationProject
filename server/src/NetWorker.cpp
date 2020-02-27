#include "../include/NetWorker.h"

NetWorker::NetWorker() {
    this->Initialize();
}

NetWorker::~NetWorker() {

}

void NetWorker::AddFd(int epollFd, int fd) {
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    epoll_ctl(epollFd, EPOLL_CTL_ADD, fd, &event);
}

bool NetWorker::Initialize() {
    struct sockaddr_in serverAddr;
    bzero(&serverAddr,sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8081);
    serverAddr.sin_addr.s_addr = inet_addr("172.24.41.154");

    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    bind(serverFd, (struct  sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverFd, 128);

    int epollFd = epoll_create(256);
    AddFd(epollFd, serverFd);

    epoll_event revs[5];
    int timeout = -1;

    while (true) {
        int ret = epoll_wait(epollFd, revs, 5, timeout);
        if (ret == 0) {
            cout << "time out" << endl;
            continue;
        }
        if (ret == -1) {
            cout << "epoll wait" << endl;
            continue;
        }

        for (int i = 0; i < ret; i++) {
            int socket = revs[i].data.fd;
            if ((serverFd == socket) && (EPOLLIN == revs->events & EPOLLIN)) {
                // connect request from client
                struct sockaddr_in clientAddr;
                socklen_t size = sizeof(clientAddr);
                int clientFd = accept(serverFd, (struct sockaddr*)&clientAddr, &size);
                if (clientFd > 0) {
                    cout << "connect success" << endl;
                }
                this->AddFd(epollFd, clientFd);
            } else if (serverFd != socket) {
                // data request from client

            } else if (revs[i].events & EPOLLOUT) {
                // write data to client

            } else {
                cout << "unknown request" << endl;
            }
        }

        
    }

    return true;
}

// TODO : 利用函数指针加入callback函数
bool NetWorker::RpcAsync(int socketFd, char* payload, int size) {

    if (!payload || size <= 0) {
        return false;
    }

    if (send(socketFd, (const char*)&size, sizeof(int), 0) < 0) {
        return false;
    }

    if (send(socketFd, payload, size, 0) < 0) {
        return false;
    }

    return true;
}