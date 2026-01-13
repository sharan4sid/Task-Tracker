#include "../include/Utils.h"
#include <iostream>
#include <ctime>

namespace Utils {

std::string getCurrentTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[20];
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d",
            1900 + ltm->tm_year,
            1 + ltm->tm_mon,
            ltm->tm_mday,
            ltm->tm_hour,
            ltm->tm_min);

    return std::string(buffer);
}

void printError(const std::string& msg) {
    std::cout << "❌ Error: " << msg << std::endl;
}

void printSuccess(const std::string& msg) {
    std::cout << "✅ " << msg << std::endl;
}

}
