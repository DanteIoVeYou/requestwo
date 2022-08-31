#include "unittest.h"
#include "requestwo.h"

/**
 * @brief test URL
 * 
 */
const std::string UnitTest::testURL = "www.baidu.com";

/**
 * @brief https://www.baidu.com:8080/index.html?x=10 
 * 
 * @return true 
 * @return false 
 */
bool UnitTest::TestParseURL1() {
    Requestwo req = "https://" + testURL + ":8080/index.html?x=10";
    std::cout << req.ToString() << std::endl;
    return true;
}


/**
 * @brief https://www.baidu.com:8080/index.html 
 * 
 * @return true 
 * @return false 
 */
bool UnitTest::TestParseURL2() {
    Requestwo req = "https://" + testURL + ":8080/index.html";
    std::cout << req.ToString() << std::endl;
    return true;
}


/**
 * @brief https://www.baidu.com/index.html 
 * 
 * @return true 
 * @return false 
 */
bool UnitTest::TestParseURL3() {
    Requestwo req = "https://" + testURL + "/index.html";
    std::cout << req.ToString() << std::endl;
    return true;
}


/**
 * @brief www.baidu.com/index.html 
 * 
 * @return true 
 * @return false 
 */
bool UnitTest::TestParseURL4() {
    Requestwo req = testURL + "/index.html";
    std::cout << req.ToString() << std::endl;
    return true;
}


/**
 * @brief 测试从配置文件读取配置项并构建http请求报文结构体
 * 
 * @return true 
 * @return false 
 */
bool UnitTest::TestBuildHttpRequest() {
    HttpRequest *req = new HttpRequest();
    Utils::BuildHttpRequest("httpRequest.config", req);
    std::cout << req->ToString() << std::endl;
    return true;
}
