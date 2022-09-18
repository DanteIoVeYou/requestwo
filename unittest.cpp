#include "unittest.h"
#include "httpRequest.h"
#include "requestwo.h"
#include <cstdlib>
#include <unistd.h>

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
    HttpRequest req(Utils::configFileName);
    std::cout << req.GetRequestMessage() << std::endl;
    return true;
}

bool UnitTest::TestSendAndRecv() {
    // for(int i = 0; i < 100; i++) {
        // Requestwo requestwo("www.baidu.com");
        Requestwo requestwo("www.qq.com");
        // usleep(600000);
    // }
    return true;
}