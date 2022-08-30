#include "utils.h"
#include "socket.h"

/**
 * @brief 解析url, 获得协议、域名、ip地址、端口号、资源虚拟路径、查询字的信息
 * 
 * @param url 
 * @param protocol 
 * @param domain 
 * @param port 
 * @param path 
 * @param query 
 */
void Utils::ParseUrl(const std::string &url, std::string *protocol, std::string *domain, std::string *port, std::string *path, std::string *query) {

    // 解析协议
    int pos_protocol = url.find("://");
    if (pos_protocol == std::string::npos) {
        // url不带协议, 默认填充为http协议
        *protocol = "http";
        pos_protocol = 0;
    }
    else {
        *protocol = url.substr(0, pos_protocol);
        pos_protocol += strlen("://");
    }

    // 解析端口
    int pos_port = url.find(':', pos_protocol);
    if(pos_port == std::string::npos) {
        // url中不包含端口号
        *port = "80";
    }
    else {
        // url中包含端口号，循环拿到端口对应的数字
        for (int i = pos_port + 1; i < url.size(); i++) {
            if (url[i] >= '0' && url[i] <= '9') {
                (*port) += url[i];
            }
            else {
                break;
            }
        }
    }

    // 解析查询词
    int pos_query = url.find('?');
    if(pos_query == std::string::npos) {
        // 没有查询词

    }
    else {
        *query = url.substr(pos_query);
    }

    // 解析路由
    int pos_path = url.find('/', pos_protocol);
    if(pos_path == std::string::npos) {
        // 路由缺失
        *path = "/index.html";
    }
    else {
        // 路由存在
        if(pos_query == std::string::npos) {
            // 查询词不存在
            *path = url.substr(pos_path);
        }
        else {
            // 查询词存在
            *path = url.substr(pos_path, pos_query - pos_path);
        }
    }

    // 解析域名
    if(pos_port == std::string::npos) {
        // 端口号缺失
        if(pos_path == std::string::npos) {
            // 路由缺失
            if(pos_query == std::string::npos) {
                // 查询词缺失
                *domain = url.substr(pos_protocol);
            }
            else {
                // 查询词存在
                *domain = url.substr(pos_protocol, pos_query - pos_protocol);
            }
        }
        else {
            // 路由存在
            *domain = url.substr(pos_protocol, pos_path - pos_protocol);
        }
    }
    else {
        // 端口号存在
        *domain = url.substr(pos_protocol, pos_port - pos_protocol);
    }
}


/**
 * @brief 域名解析为ip地址
 * 
 * @param domain 
 * @param ip 
 */
void Utils::ParseIp(const std::string &domain, std::string *ip) {
        // 判断m_domain是否为域名
         if(Utils::IsDomain(domain)) {
             //入参是域名，则解析出对于的ip
             *ip = Socket::Domain2Ip(domain);
         }
         else {
             //入参是ip地址
             *ip = domain;
         }
}


/**
 * @brief 判断入参是否为一个合法的domain
 * 
 * @param domain 
 * @return true 
 * @return false 
 */
bool Utils::IsDomain(std::string domain) {
    int pos = domain.rfind('.');
    std::string last_seg = domain.substr(pos);
    if(HasNumber(last_seg)) {
        // 顶级域名包含数字，则这是一个ip地址而不是域名
        return false;
    }
    else {
        return true;
    }
}


/**
 * @brief 判断入参是否含有0-9的数字
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool Utils::HasNumber(const std::string &str) {
    for(const auto &ch: str) {
        if(ch >= '0' && ch <= '9') {
            return true;
        }
    }
    return false;
}