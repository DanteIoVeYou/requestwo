#pragma once
#include<string>
#include<unordered_map>
#include <algorithm>
#include "utils.h"

struct HttpRequest {

    /**
     * @brief Construct a new Http Request object
     * 
     */
    HttpRequest() {}


    /**
     * @brief Construct a new http Request object
     * 
     * @param http_request_map 
     */
    HttpRequest() {
        std::transform(m_http_request_line_method.begin(), m_http_request_line_method.end(), m_http_request_line_method.begin(), ::toupper);
    }

    /**
     * @brief 以字符串的形式打印成员函数
     * 
     * @return std::string 
     */
    std::string ToString() {
        return 
            "Method: " + m_http_request_line_method + "\n" + 
            "Path: " + m_http_request_line_path + "\n" + 
            "Version: " + m_http_request_line_protocol_version + "\n" + 
            "Host: " + m_http_request_header_host + "\n" + 
            "Connection: " + m_http_request_header_connection + "\n" + 
            "ContentLength: " + m_http_request_header_content_length + "\n" +
            "ContentType: " + m_http_request_header_content_type + "\n" +
            "UserAgent: " + m_http_request_header_user_agent + "\n" + 
            "Accept: " + m_http_request_header_accept + "\n" +
            "Referer: " + m_http_request_header_referer + "\n" +
            "AcceptLanguage: " + m_http_request_header_accept_language + "\n";
    }

    /**
     * @brief Get the Request Message
     * 
     * @return std::string 
     */
    std::string GetRequestMessage() {
        if(!BuildHttpRequest()) {

        }
        else {
            return m_http_reqeuest_message;
        }
    }

    /**
     * @brief 处理配置文件
     * 
     * @return true 
     * @return false 
     */
    bool ParseConfigFile() {
        std::unordered_map<std::string, std::string> http_request_map = {
            {"Method", ""},
            {"Path", ""},
            {"Version", ""},
            {"Host", ""},
            {"Connection", ""},
            {"ContentLength", ""},
            {"ContentType", ""},
            {"UserAgent", ""},
            {"Accept", ""},
            {"Referer", ""},
            {"AcceptLanguage", ""}
        };
        Utils::ReadConfigFile(Utils::configFileName, http_request_map);
        m_http_request_line_method = http_request_map["Method"];
        m_http_request_line_path = http_request_map["Path"];
        m_http_request_line_protocol_version = http_request_map["Version"];
        m_http_request_header_host = http_request_map["Host"];
        m_http_request_header_connection = http_request_map["Connection"];
        m_http_request_header_content_length = http_request_map["ContentLength"];
        m_http_request_header_content_type = http_request_map["ContentType"];
        m_http_request_header_user_agent = http_request_map["UserAgent"];
        m_http_request_header_accept = http_request_map["Accept"];
        m_http_request_header_referer = http_request_map["Referer"];
        m_http_request_header_accept_language = http_request_map["AcceptLanguage"];
        return true;
    }

    /**
     * @brief 构建请求行
     * 
     * @return true 
     * @return false 
     */
    bool BuildHttpRequestLine() {
        m_http_request_line += m_http_request_line_method;
        m_http_request_line += " ";
        m_http_request_line += m_http_request_line_path;
        m_http_request_line += " ";
        m_http_request_line += m_http_request_line_protocol_version;
        m_http_request_line += Utils::LF;
        return true;
    }

    /**
     * @brief 构建请求报头
     * 
     * @return true 
     * @return false 
     */
    bool BuildHttpRequestHeader() {
        m_http_request_header += m_http_request_header_host;
        m_http_request_header += Utils::LF;
        m_http_request_header += m_http_request_header_connection;
        m_http_request_header += Utils::LF;
        m_http_request_header += m_http_request_header_content_length;
        m_http_request_header += Utils::LF;
        m_http_request_header += m_http_request_header_content_type;
        m_http_request_header += Utils::LF;
        m_http_request_header += m_http_request_header_user_agent;
        m_http_request_header += Utils::LF;
        m_http_request_header += m_http_request_header_accept;
        m_http_request_header += Utils::LF;
        m_http_request_header += m_http_request_header_referer;
        m_http_request_header += Utils::LF;
        m_http_request_header += m_http_request_header_accept_language;
        m_http_request_header += Utils::LF;
        return true;
    }

    /**
     * @brief 构建请求体
     * 
     * @return true 
     * @return false 
     */
    bool BuildHttpRequestBody() {

    }

    /**
     * @brief 构建空行 
     * 
     * @return true 
     * @return false 
     */
    bool BuildBlankLine() {
        m_http_reqeuest_blankline = Utils::LF;
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool BuildHttpRequest () {
        ParseConfigFile();
        BuildHttpRequestLine();
        BuildHttpRequestHeader();
        BuildBlankLine();
        if(m_http_request_line_method == "POST") {
            BuildHttpRequestBody();
        }
        m_http_reqeuest_message += m_http_request_line;
        m_http_reqeuest_message += m_http_request_header;
        m_http_reqeuest_message += m_http_reqeuest_blankline;
        m_http_reqeuest_message += m_http_reqeuest_body;
    }

    /**
     * @brief http报文
     * 
     */
    std::string m_http_reqeuest_message;
    /**
     * @brief http请求行
     * 
     */
    std::string m_http_request_line;
    /**
     * @brief http请求行的请求方法
     * 
     */
    std::string m_http_request_line_method;
    /**
     * @brief http请求行的请求资源路由
     * 
     */
    std::string m_http_request_line_path;
    /** 
     * @brief http请求行的http版本号 
     * 
     */
    std::string m_http_request_line_protocol_version;
    /**
     * @brief http请求报头 
     * 
     */
    std::string m_http_request_header;
    /**
     * @brief http请求报头的请求目标主机的域名
     * 
     */
    std::string m_http_request_header_host;
    /**
     * @brief http请求报头的的connection header属性，决定当前事务完成之后是否关闭当前的网络连接
     * 
     */
    std::string m_http_request_header_connection;
    /**
     * @brief http请求报头的body的长度 
     * 
     */
    std::string m_http_request_header_content_length;
    /**
     * @brief http请求报头的数据类型
     * 
     */
    std::string m_http_request_header_content_type;
    /**
     * @brief http请求报头的包含操作系统和浏览器版本的信息
     * 
     */
    std::string m_http_request_header_user_agent;
    /**
     * @brief http请求报头告诉服务器希望返回的body数据的类型
     * 
     */
    std::string m_http_request_header_accept;
    /**
     * @brief http请求报头中包含从哪一个页面跳转过来的信息
     * 
     */
    std::string m_http_request_header_referer;
    /**
     * @brief http请求报头中表示希望服务器返回的语言类型
     * 
     */
    std::string m_http_request_header_accept_language;
    /**
     * @brief 空行
     * 
     */
    std::string m_http_reqeuest_blankline;
    /**
     * @brief http请求报头的请求体 
     * 
     */
    std::string m_http_reqeuest_body;
};