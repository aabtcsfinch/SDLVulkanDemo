
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class GameState
{
    public:
        virtual void Init() = 0;
        virtual void CleanUp() = 0;

        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void ProccessInput(Game* g) = 0;
        virtual void Update(Game* g) = 0;
        virtual void Draw(Game* g) = 0;
        void ChangeState(Game* g, GameState* state){ g->ChangeState(state); }
    
    protected:
        GameState(){}
};
#endif