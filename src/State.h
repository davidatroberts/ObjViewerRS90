#ifndef STATE_H
#define STATE_H

#include <SDL/SDL_keysym.h>
#include <SDL/SDL_video.h>

struct State
{
    virtual ~State() = default;
    virtual void enterState() = 0;
    virtual void leaveState() = 0;
    virtual void update(float delta) = 0;
    virtual void render() = 0;
    virtual void handleKeyDown(const SDLKey &key) = 0;
    virtual void handleKeyUp(const SDLKey &key) = 0;
};

#endif