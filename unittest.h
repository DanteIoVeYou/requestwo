#pragma once


#include <iostream>
#include <string>
#include <cstring>

class UnitTest {

public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool TestParseURL1();
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool TestParseURL2();
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool TestParseURL3();
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool TestParseURL4();

    /**
     * @brief a unittest URL
     * 
     */
    const static std::string testURL;
};