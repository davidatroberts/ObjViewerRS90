#include "ObjParser.h"

#include <iostream>
#include <iterator>
#include <sstream>

#include "Face.h"
#include "Vector3.h"
#include "VertexTexture.h"

namespace 
{
    void processLine(const std::string &line, geometry::Model &model)
    {
        std::istringstream iss(line);
        std::vector<std::string> results(
            std::istream_iterator<std::string>{iss},
            std::istream_iterator<std::string>()
        );

        if (results.empty())
            return;

        const auto key = results.front();
        results.erase(results.begin());

        if (key == "#")
            return;

        if (key == "v")
        {
            model.vectors.push_back(geometry::createVector(results));
            return;
        }

        if (key == "vt")
        {
            model.vertex_textures.push_back(geometry::createVertexTexture(results));
            return;
        }

        if (key == "vn")
        {
            model.vertex_normals.push_back(geometry::createVector(results));
            return;
        }

        if (key == "f")
        {
            model.faces.push_back(geometry::createFace(results));
            return;
        }

        std::cout << "Unsupported obj command\n";
    }
}

namespace obj_parser
{
    geometry::Model parseObjectFile(const std::string &file_name)
    {
        std::ifstream file_stream(file_name);
        return parserObjectStream(file_stream);
    }

    geometry::Model parserObjectStream(std::istream &stream)
    {
        geometry::Model model;

        std::string line;
        while (std::getline(stream, line))
        {
            processLine(line, model);
        }
        
        return model;
    }
} 