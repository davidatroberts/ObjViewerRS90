#include "Vector3.h"

#include <sstream>

namespace geometry
{
    Vector3 createVector(const std::vector<std::string> &string_vals)
    {
        if (string_vals.size() == 3)
            return Vector3(
                std::stof(string_vals[0]), std::stof(string_vals[1]), std::stof(string_vals[2]));

        if (string_vals.size() == 4)
            return Vector3(
                std::stof(string_vals[0]), 
                std::stof(string_vals[1]), 
                std::stof(string_vals[2]), 
                std::stof(string_vals[3]));

        return Vector3();
    }
}