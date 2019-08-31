#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>
#include <vector>

namespace string_util
{
    std::vector<std::string> splitString(const std::string &str, const std::string &delimiter);
}

#endif