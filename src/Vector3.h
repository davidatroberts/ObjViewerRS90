#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>

namespace geometry
{
    struct Vector3
    {
        Vector3(float x=0, float y=0, float z=0, float w=1):
            x(x), y(y), z(z), w(w)
        {
        }

        float x, y, z, w;
    };

    Vector3 createVector(
        const std::string &x_str, const std::string &y_str, const std::string &z_str, const std::string &w_str=""
    );
}

#endif