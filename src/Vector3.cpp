#include "Vector3.h"

#include <sstream>

namespace geometry
{
    Vector3 createVector(
        const std::string &x_str, const std::string &y_str, const std::string &z_str, const std::string &w_str)
    {
        if (w_str.empty())
            return Vector3(std::stof(x_str), std::stof(y_str), std::stof(z_str));
        
        return Vector3(std::stof(x_str), std::stof(y_str), std::stof(z_str), std::stof(w_str));
    }
}