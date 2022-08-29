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
    /**
     * @brief 域名解析
     * 
     * @param domain 
     * @return std::string 
     */
    static std::string Domain2Ip(std::string domain);

    /**
     * @brief Create a Socket object 创建套接字
     * 
     * @return int 
     */
    static int CreateSocket();
    
    /**
     * @brief 连接远端
     * 
     * @param fd 
     * @param ip 
     * @param port 
     */
    static void Connect(int fd, std::string ip, uint16_t port);
};