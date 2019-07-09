#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>

namespace geometry
{
    struct Vector3
    {
        Vector3(float x=0, float y=0, float z=0):
            x(x), y(y), z(z)
        {
        }

        float x, y, z;
    };

    Vector3 createVector(
        const std::string &x_str, const std::string &y_str, const std::string &z_str
    );
}

#endif