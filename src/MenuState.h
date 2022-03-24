#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "../libs/SDL2/include/SDL.h"
#include "GameState.h"

class MenuState : public GameState
{
    public:
        void Init();
        void CleanUp();
        void Pause();
        void Resume();

        void ProccessInput(Game* game);
        void Update(Game* game);
        void Draw(Game* game);

        static MenuState* Instance() { return &instance; }

    protected:
        MenuState(){}

    private:
        static MenuState instance;
        SDL_Surface* bg;
};
#endif