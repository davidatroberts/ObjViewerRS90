#ifndef OBJVIEWERSTATE_H
#define OBJVIEWERSTATE_H

#include <memory>
#include <string>

struct State;
struct Context;

std::shared_ptr<State> createObjViewerState(
    std::shared_ptr<Context> context, 
    const std::string &obj_file
);

#endif