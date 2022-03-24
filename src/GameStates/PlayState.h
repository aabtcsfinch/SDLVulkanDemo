#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <SDL2/SDL.h>
#include "GameState.h"

class PlayState : public GameState
{
    public:
        void Initialize();
        void CleanUp();

        void Pause();
        void Resume();

        void ProcessInput(Game* game);
        void Update(Game* game);
        void Draw(Game* game);

        static PlayState* Instance() { return &instance; }

    protected:
        PlayState(){}

    private:
        static PlayState instance;
        SDL_Texture* bg;
};

#endif