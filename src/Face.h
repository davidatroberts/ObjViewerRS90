#ifndef FACE_H
#define FACE_H

#include <string>
#include <vector>

namespace geometry
{
    struct Face
    {
        std::vector<size_t> vertex_indices;
    };
    

    Face createFace(const std::vector<std::string> &vector_string_values);
}

#endif