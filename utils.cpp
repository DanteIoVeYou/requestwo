#include "utils.h"
#include "socket.h"

/**
 * @brief 配置文件名
 * 
 */
const std::string Utils::configFileName = "httpRequest.config";
const std::string Utils::commentMark = "#";
const std::string Utils::LF = "\r\n";

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



/**
 * @brief 读取配置文件，将键值对存入哈希表 
 * 
 * @param filename 配置文件名 
 * @param map
 * @return true 
 * @return false 
 */
bool Utils::ReadConfigFile(const std::string &filename, std::unordered_map<std::string, std::string> &map) {
    std::ifstream in(filename);
    if(in.is_open()) {
        std::string line;
        while(std::getline(in, line)) {
            // 判断该行是否是注释
            bool is_comment = IsComment(line, commentMark);
            // 判断该行是否为空行
            bool is_blackline = IsBlankLine(line);
            if(is_comment || is_blackline) {
                continue;
            }
            else {
                const std::string sep = "=";
                std::string key;
                std::string value;
                int ret = GetKeyValue(line, sep, &key, &value);
                if(!ret) {
                    // error
                }
                else {
                    if(key.size() == 0 || value.size() == 0) {
                        continue;
                    }
                    else {
                        if(map.find(key) != map.end()) {
                            // 找到对应的键
                            map[key] = value;
                        }
                        else {
                            // 非法的键
                            continue;
                        }
                    }
                }
            }
        }
    }
    else {
        // error
    }
}

/**
 * @brief 判断行文本是否为被mark标注的注释行 
 * 
 * @param line 
 * @param mark 
 * @return true 
 * @return false 
 */
bool Utils::IsComment(const std::string &line, const std::string &mark) {
    for (int i = 0; i < line.size(); i++) {
        if(line[i] == ' ') {
            continue;
        }
        else {
            bool flag = true;
            for (int j = 0; j < mark.size(); j++) {
                if(line[i+j] != mark[j] || i+j >= line.size()) {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
    }
    return false;
}

/**
 * @brief 判断line是否为空行 
 * 
 * @param line 
 * @return true 
 * @return false 
 */
bool Utils::IsBlankLine(const std::string &line) {
    return (line.size() == 0);
}

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
bool Utils::GetKeyValue(const std::string &line, const std::string &sep, std::string *key, std::string *value) {
    // 跳过空格
    int pos_start = 0;
    for (; pos_start < line.size(); pos_start++) {
        if(line[pos_start] == ' ') {
            continue;
        }
        else {
            break;
        }
    }
    std::string new_line = line.substr(pos_start);
    int pos_sep = new_line.find(sep);
    if(pos_sep == std::string::npos) {
        // 没有找到分隔符
        return false;
    }
    *key = new_line.substr(0, pos_sep);
    *value = new_line.substr(pos_sep + 1);
    return true;
}