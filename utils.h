#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>


class Utils {
public:
    static bool IsDomain(std::string domain);
    static bool HasNumber(const std::string &str);
};