// #include "socket.cpp"
#include "requestwo.h"
#include <iostream>
int main()
{
    std::string domain = "www.imdanteking.com";
    // std::cout << Socket::Domain2Ip(domain) << std::endl;
    Requestwo requestwo = domain;
    std::cout << requestwo.m_ip << std::endl;
    return 0;
}