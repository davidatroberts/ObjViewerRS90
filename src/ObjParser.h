#ifndef OBJPARSER_H
#define OBJPARSER_H
    
#include <string>
#include <fstream>

#include "Model.h"

namespace obj_parser
{
    geometry::Model parseObjectFile(const std::string &file_name);
    geometry::Model parserObjectStream(std::ifstream &file_stream);
}

#endif