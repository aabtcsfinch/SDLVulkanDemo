#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "../libs/SDL2/include/SDL.h"
#include "GameState.h"

class SplashScreen : public GameState
{
    public:
        void Init();
        void CleanUp();

        void Pause();
        void Resume();

        void HandleEvents(GameEngine* game);
        void Update(GameEngine* game);
        void Draw(GameEngine* game);

        static SplashScreen* Instance() { return &instance; }

    protected:
        SplashScreen(){}

    private:
        static SplashScreen instance;
        SDL_Surface* bg;
};
#endif