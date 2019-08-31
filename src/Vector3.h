#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>
#include <vector>

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

    Vector3 createVector(const std::vector<std::string> &string_vals);
}

#endif