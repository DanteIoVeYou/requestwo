#include "socket.h"


/**
 * @brief 域名解析
 * 
 * @param domain 
 * @return std::string 
 */
std::string Socket::Domain2Ip(std::string domain) {
    struct hostent *host = gethostbyname(domain.c_str());
    if(host == nullptr) {
        // error
        return "";
    }
    else {
        std::string ip = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
        return ip;
    }
}


/**
 * @brief Create a Socket object 创建套接字
 * 
 * @return int 
 */
int Socket::CreateSocket() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0 ) {
        // error
        std::cout << "create socket failed" << std::endl; 
    }
    return fd;
}


/**
 * @brief 连接远端
 * 
 * @param fd 
 * @param ip 
 * @param port 
 */
void Socket::Connect(int fd, std::string ip, uint16_t port) {
    sockaddr_in peer;
    bzero(&peer, sizeof(peer));
    peer.sin_family = AF_INET;
    peer.sin_port = htons(port);
    peer.sin_addr.s_addr = inet_addr(ip.c_str());
    if(connect(fd, (sockaddr*)&peer, sizeof(peer)) == 0) {
        std::cout << "connect success" << std::endl; 
    }
    else {
        // error
        std::cout << "connect failed" << std::endl; 
    }
}

/**
 * @brief 发送信息
 * 
 * @param fd
 * @param message
 */
bool Socket::Send(int fd, std::string message) {
    char ch = 0;
    for (int i = 0; i < message.size(); i++)
    {
        ch = message[i];
        int ret = send(fd, &ch, 1, 0);
        if(ret == -1) {
            return false;
        }
    }
    return true;
}