#include "Face.h"

#include "StringUtil.h"

namespace geometry
{
    Face createFace(const std::vector<std::string> &face_values)
    {
        Face f;

        const auto delim = "/";
        for (const auto &face_value: face_values)
        {
            const auto face_line = string_util::splitString(face_value, delim);

            if (face_line.size() > 0)
            {
                const int vector_index = std::stoi(face_line[0]) - 1;
                f.vertex_indices.push_back(static_cast<size_t>(vector_index));
            }
            if ((face_line.size() > 1) && (face_line[1] != ""))
            {
                const int vertex_texture_index = std::stoi(face_line[1]) - 1;
                f.vertex_texture_indices.push_back(static_cast<size_t>(vertex_texture_index)); 
            }
            if (face_line.size() > 2)
            {
                const int vertex_normal_index = std::stoi(face_line[2]) - 1;
                f.vertex_normal_indices.push_back(static_cast<size_t>(vertex_normal_index));
            }
        }

        return f;
    }
}