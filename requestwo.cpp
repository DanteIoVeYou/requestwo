#include "requestwo.h"

Requestwo::Requestwo(std::string domain): m_domain(domain) {
        // 判断入参是否为域名
        if(Utils::IsDomain(domain)) {
            // 入参是域名，则解析出对于的ip
            m_ip = Socket::Domain2Ip(domain);
        }
        else {
            // 入参是ip地址
            m_ip = m_domain;
        }
}
Requestwo::~Requestwo() {}