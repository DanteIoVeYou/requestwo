#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "utils.h"
#include "socket.h"
#include "httpRequest.h"
#include "httpResponse.h"

class Requestwo {

public:
    /**
     * @brief Construct a new Requestwo object 入参为url的构造函数
     * 
     * @param url 
     */
    Requestwo(std::string url);

    /**
     * @brief Destroy the Requestwo object 析构函数
     * 
     */
    ~Requestwo();

    /**
     * @brief 以字符串的形式打印所有成员变量
     * 
     * @return std::string 
     */
    std::string ToString();

private:
    /**
     * @brief URL 
     * 
     */
    std::string m_url;
    /**
     * @brief 协议 
     * 
     */
    std::string m_protocol;
    /**
     * @brief 域名 
     * 
     */
    std::string m_domain;
    /**
     * @brief ip地址
     * 
     */
    std::string m_ip;
    /**
     * @brief 端口号
     * 
     */
    std::string m_port;
    /**
     * @brief 资源路由
     * 
     */
    std::string m_path;
    /**
     * @brief 查询词 
     * 
     */
    std::string m_query;
};