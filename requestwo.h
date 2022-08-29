#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "utils.h"
#include "socket.h"

class Requestwo {
public:
    Requestwo(std::string domain);
    ~Requestwo();

private:

public:
    std::string m_domain;
    std::string m_ip;
};