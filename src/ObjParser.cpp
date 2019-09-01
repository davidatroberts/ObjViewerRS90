#include "ObjParser.h"

#include <iostream>
#include <iterator>
#include <sstream>

#include "Face.h"
#include "Vector3.h"
#include "VertexTexture.h"

namespace 
{
    bool processLine(const std::string &line, geometry::Model &model)
    {
        std::istringstream iss(line);
        std::vector<std::string> results(
            std::istream_iterator<std::string>{iss},
            std::istream_iterator<std::string>()
        );

        if (results.empty())
            return true;

        const auto key = results.front();
        results.erase(results.begin());

        if (key == "#")
            return true;

        if (key == "v")
        {
            model.vectors.push_back(geometry::createVector(results));
            return true;
        }

        if (key == "vt")
        {
            model.vertex_textures.push_back(geometry::createVertexTexture(results));
            return true;
        }

        if (key == "vn")
        {
            model.vertex_normals.push_back(geometry::createVector(results));
            return true;
        }

        if (key == "f")
        {
            model.faces.push_back(geometry::createFace(results));
            return true;
        }

        // todo implement these
        if (key == "g")
            return true;

        if (key == "s")
            return true;

        return false;
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
            if (!processLine(line, model))
                std::cout << "Unable to parse: " << line << "\n";
        }
        
        return model;
    }
} 