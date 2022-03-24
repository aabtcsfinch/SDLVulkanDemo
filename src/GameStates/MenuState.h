#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameState.h"

class MenuState : public GameState
{
    public:
        void Initialize();
        void CleanUp();

        void Pause();
        void Resume();

        void ProcessInput(Game* game);
        void Update(Game* game);
        void Draw(Game* game);

        static MenuState* Instance() { return &instance; }

    private:
        static MenuState instance;
        SDL_Texture* bg;
};

#endif