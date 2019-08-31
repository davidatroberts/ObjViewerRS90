#include "ObjViewerState.h"

#include "Context.h"
#include "State.h"

class ObjViewerState: public State
{
public:
    ObjViewerState(std::shared_ptr<Context> context, std::string obj_file):
        context_(context), obj_file_(obj_file)
    {
    }

    void enterState() override
    {
        context_->loadObjFile(obj_file_);
    }

    void leaveState() override
    {
    }

    void update(float delta) override
    {
    }

    void render() override
    {
    }

    void handleKeyDown(const SDLKey &key) override
    {
    }

    void handleKeyUp(const SDLKey &key) override
    {
    }

private:
    std::shared_ptr<Context> context_;
    std::string obj_file_;
};

std::shared_ptr<State> createObjViewerState(
    std::shared_ptr<Context> context, const std::string &obj_file
)
{
    return std::make_shared<ObjViewerState>(context, obj_file);
}