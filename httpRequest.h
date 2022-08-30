#pragma once
#include<string>

struct httpRequest {

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

};