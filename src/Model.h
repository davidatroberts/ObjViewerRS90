#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "Vector3.h"

namespace geometry
{
    struct Model
    {
        std::vector<Vector3> vectors;
    };
}

#endif