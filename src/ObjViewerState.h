#ifndef OBJVIEWERSTATE_H
#define OBJVIEWERSTATE_H

#include <memory>

struct State;
struct Context;

std::shared_ptr<State> createObjViewerState(std::shared_ptr<Context> context);

#endif