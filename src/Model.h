#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "Face.h"
#include "Vector3.h"
#include "VertexTexture.h"

namespace geometry
{
    struct Model
    {
        std::vector<Vector3> vectors;
        std::vector<VertexTexture> vertex_textures;
        std::vector<Face> faces;
    };
}

#endif