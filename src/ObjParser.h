#ifndef OBJPARSER_H
#define OBJPARSER_H
    
#include <string>

#include "Model.h"

namespace obj_parser
{
    geometry::Model parseObjectFile(const std::string &file_name);
}

#endif