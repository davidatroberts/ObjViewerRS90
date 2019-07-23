#include "Face.h"

namespace geometry
{
    Face createFace(const std::vector<std::string> &vector_string_values)
    {
        Face f;
        for (const auto &vector_string: vector_string_values)
        {
            const int vector_index = std::stoi(vector_string) - 1;
            f.vertex_indices.push_back(static_cast<size_t>(vector_index));
        }

        return f;
    }
}