#ifndef VERTEXTEXTURE_H
#define VERTEXTEXTURE_H

#include <string>
#include <vector>

namespace geometry
{
    struct VertexTexture
    {
        VertexTexture(float u=0, float v=0, float w=0):
            u(u), v(v), w(w)
        {
        }

        float u, v, w;
    };

    VertexTexture createVertexTexture(
        const std::vector<std::string> &string_vals
    );
}

#endif