#ifndef VERTEXTEXTURE_H
#define VERTEXTEXTURE_H

#include <string>

namespace geometry
{
    struct VertexTexture
    {
        VertexTexture(float u, float v=0, float w=0):
            u(u), v(v), w(w)
        {
        }

        float u, v, w;
    };
    
    VertexTexture createVertexTexture(
        const std::string &u_str, const std::string &v_str="", const std::string &w_str=""
    );
}

#endif