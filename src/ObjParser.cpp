#include "ObjParser.h"

#include <iostream>
#include <iterator>
#include <sstream>

#include "Vector3.h"

namespace 
{
    void processLine(const std::string &line, geometry::Model &model)
    {
        std::istringstream iss(line);
        const std::vector<std::string> results(
            std::istream_iterator<std::string>{iss},
            std::istream_iterator<std::string>()
        );

        if (results.empty())
            return;

        const auto key = results.front();
        if (key == "#")
            return;

        if (key == "v")
        {
            if (results.size()==4)
                model.vectors.push_back(geometry::createVector(results[1], results[2], results[3]));
            else if (results.size() == 5)
                model.vectors.push_back(geometry::createVector(results[1], results[2], results[3], results[4]));
        }

        std::cout << "Unsupport obj command\n";
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