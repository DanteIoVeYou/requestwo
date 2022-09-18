#include "requestwo.h"



/**
 * @brief Construct a new Requestwo:: Requestwo object 入参为url的构造函数
 * 
 * @param url 
 */
Requestwo::Requestwo(std::string url): m_url(url) {
        // 解析url
        Utils::ParseUrl(url, &m_protocol, &m_domain, &m_port, &m_path, &m_query);
        // 解析ip地址
        Utils::ParseIp(m_domain, &m_ip);
        // 构建http请求类，获得序列化的http报文
        HttpRequest http_request(Utils::configFileName);
        std::string http_request_message = http_request.GetRequestMessage();
        std::cout << http_request_message << std::endl;
        // 发送请求
        int sock = Socket::CreateSocket();
        Socket::Connect(sock, m_ip, (uint16_t)atoi(m_port.c_str()));
        Socket::Send(sock, http_request_message);
        // 接收响应
        std::string resp;
        // char buffer[81920];
        // ssize_t len = recv(sock, buffer, sizeof(buffer)-1, 0);
        // buffer[len] = 0;
        // resp = buffer;
        char ch;
        while(recv(sock, &ch, 1, 0)) {
            resp += ch;
            if(resp.find("</html>") != std::string::npos) {
                break;
            }
        }
        std::cout << resp << std::endl;
}


/**
 * @brief Destroy the Requestwo:: Requestwo object 析构函数
 * 
 */
Requestwo::~Requestwo() {}


/**
 * @brief 以字符串的形式打印所有成员变量
 * 
 * @return std::string 
 */
std::string Requestwo::ToString() {
    return "协议： " + m_protocol + "\n" + "域名： " + m_domain + "\n" + "ip： " + m_ip + "\n" + "端口号： " + m_port + "\n" + "资源路由： " + m_path + "\n" + "查询词： " + m_query + "\n";
}