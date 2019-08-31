#ifndef FACE_H
#define FACE_H

#include <string>
#include <vector>

namespace geometry
{
    struct Face
    {
        std::vector<size_t> vertex_indices;
        std::vector<size_t> vertex_texture_indices;
        std::vector<size_t> vertex_normal_indices;
    };
    

    Face createFace(const std::vector<std::string> &face_values);
}

#endif