#include "StringUtil.h"

namespace string_util
{
    std::vector<std::string> splitString(const std::string &str, const std::string &delimiter)
    {
        std::vector<std::string> result;

        auto start = 0U;
        auto end = str.find(delimiter);
        while (end != std::string::npos)
        {
            result.emplace_back(str.substr(start, end - start));
            start = end + delimiter.length();
            end = str.find(delimiter, start);
        }

        result.emplace_back(str.substr(start, end));

        return result;
    }
}