#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
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
     * @brief 域名解析为ip地址
     * 
     * @param domain 
     * @param ip 
     */
    static void ParseIp(const std::string &domain, std::string *ip);

    /**
     * @brief 读取配置文件，将键值对存入哈希表 
     * 
     * @param filename 配置文件名 
     * @param map
     * @return true 
     * @return false 
     */
    static bool ReadConfigFile(const std::string &filename, std::unordered_map<std::string, std::string> &map);

    /**
     * @brief 以sep为分隔符读取key和value
     * 
     * @param line 
     * @param sep 
     * @param key 
     * @param value 
     * @return true 
     * @return false 
     */
    static bool GetKeyValue(const std::string &line, const std::string &sep, std::string *key, std::string *value);

private:
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

    /**
     * @brief 判断行文本是否为被mark标注的注释行 
     * 
     * @param line 
     * @param mark 
     * @return true 
     * @return false 
     */
    static bool IsComment(const std::string &line, const std::string &mark);

    /**
     * @brief 判断line是否为空行 
     * 
     * @param line 
     * @return true 
     * @return false 
     */
    static bool IsBlankLine(const std::string &line);

public:
    /**
     * @brief 配置文件名
     *
     */

    const static std::string configFileName;
    /**
     * @brief 注释标记
     * 
     */
    const static std::string commentMark;

    /**
     * @brief 回车换行
     * 
     */
    const static std::string LF;

};