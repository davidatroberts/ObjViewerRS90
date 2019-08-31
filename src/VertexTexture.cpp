#include "VertexTexture.h"

#include <sstream>

namespace geometry
{
    VertexTexture createVertexTexture(
        const std::vector<std::string> &string_vals)
    {
        if (string_vals.size() == 1)
            return VertexTexture(std::stof(string_vals[0]));
        
        if (string_vals.size() == 2)
            return VertexTexture(std::stof(string_vals[0]), std::stof(string_vals[1]));

        if (string_vals.size() == 3)
            return VertexTexture(std::stof(string_vals[0]), std::stof(string_vals[1]), std::stof(string_vals[2]));

        return VertexTexture();
    }
}