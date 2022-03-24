#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../Game.h"

class GameState
{
    public:
        virtual void Initialize() = 0;
        virtual void CleanUp() = 0;

        virtual void Pause() = 0;
        virtual void Resume() = 0;

        virtual void ProcessInput(Game* game) = 0;
        virtual void Update(Game* game) = 0;
        virtual void Draw(Game* game) = 0;

        void ChangeState(Game* game, GameState* state) { game->ChangeState(state); }
    
    protected:
        GameState(){}
        ~GameState(){}

};

#endif