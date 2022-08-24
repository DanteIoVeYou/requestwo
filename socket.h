#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

class Socket {
public:
    // 域名解析
    static std::string Domain2Ip(std::string domain);
    // 创建套接字
    static int CreateSocket();
    // 连接远端
    static void Connect(int fd, std::string ip, uint16_t port);
};