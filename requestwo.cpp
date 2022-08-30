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
        // 读取配置文件
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