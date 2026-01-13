#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    std::string getCurrentTimestamp();
    void printError(const std::string& msg);
    void printSuccess(const std::string& msg);
}

#endif
