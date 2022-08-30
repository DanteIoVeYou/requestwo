#include "requestwo.h"


/**
 * @brief Construct a new Requestwo:: Requestwo object 入参为url的构造函数
 * 
 * @param url 
 */
Requestwo::Requestwo(std::string url): m_url(url) {
        // 解析url
        Utils::ParseUrl(url, &m_protocol, &m_domain, &m_port, &m_path, &m_query);
        // 判断m_domain是否为域名
         if(Utils::IsDomain(m_domain)) {
             //入参是域名，则解析出对于的ip
             m_ip = Socket::Domain2Ip(m_domain);
         }
         else {
             //入参是ip地址
             m_ip = m_domain;
         }
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