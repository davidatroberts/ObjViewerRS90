#include "VertexTexture.h"

#include <sstream>

namespace geometry
{
    VertexTexture createVertexTexture(
        const std::string &u_str, const std::string &v_str, const std::string &w_str)
    {
        if (v_str.empty())
            return VertexTexture(std::stof(u_str));

        if (w_str.empty())
            return VertexTexture(std::stof(u_str), std::stof(v_str));

        return VertexTexture(std::stof(u_str), std::stof(v_str), std::stof(w_str));
    }
}