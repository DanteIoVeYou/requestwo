#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>


class Utils {
public:

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
    static void ParseUrl(const std::string &url, std::string *protocol, std::string *domain, std::string *port, std::string *path, std::string *query);

    /**
     * @brief 判断入参是否为一个合法的domain 
     * 
     * @param domain 
     * @return true 
     * @return false 
     */
    static bool IsDomain(std::string domain);

    /**
     * @brief 判断入参是否含有0-9的数字
     * 
     * @param str 
     * @return true 
     * @return false 
     */
    static bool HasNumber(const std::string &str);
};