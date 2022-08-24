#include "socket.cpp"

int main()
{
    std::string domain = "www.imdanteking.com";
    std::cout << Socket::Domain2Ip(domain) << std::endl;
    return 0;
}