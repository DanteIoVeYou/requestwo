#include "socket.h"

std::string Socket::Domain2Ip(std::string domain) {
    struct hostent *host = gethostbyname(domain.c_str());
    if(host == nullptr) {
        // error
    }
    else {
        std::string ip = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
        return ip;
    }
}

int Socket::CreateSocket() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0 ) {
        // error
        std::cout << "create socket failed" << std::endl; 
    }
    return fd;
}

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