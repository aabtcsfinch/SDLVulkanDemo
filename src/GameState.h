
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameEngine.h"

class GameState
{
    public:
        virtual void Init() = 0;
        virtual void CleanUp() = 0;

        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void HandleEvents(GameEngine* g) = 0;
        virtual void Update(GameEngine* g) = 0;
        virtual void Draw(GameEngine* g) = 0;
        void ChangeState(GameEngine* g, GameState* state){ g->ChangeState(state); }
    
    protected:
        GameState(){}
};
#endif