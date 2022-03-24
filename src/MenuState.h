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

        void HandleEvents(GameEngine* game);
        void Update(GameEngine* game);
        void Draw(GameEngine* game);

        static MenuState* Instance() { return &instance; }

    protected:
        MenuState(){}

    private:
        static MenuState instance;
        SDL_Surface* bg;
};
#endif