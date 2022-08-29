#include "utils.h"

bool Utils::IsDomain(std::string domain) {
    int pos = domain.rfind('.');
    std::string lastSeg = domain.substr(pos);
    if(HasNumber(lastSeg)) {
        // 顶级域名包含数字，则这是一个ip地址而不是域名
        return false;
    }
    else {
        return true;
    }
}

bool Utils::HasNumber(std::string str) {
    for(const auto &ch: str) {
        if(ch >= '0' || ch <= '9') {
            return true;
        }
    }
    return false;
}