#include "GameEngine.h"
#include "../libs/SDL2/include/SDL.h"
#include "../libs/SDL2/include/SDL_vulkan.h"
#include "vk_types.h"
#include "vk_initializers.h"

void GameEngine::Init(const char* title, int width=1920, int height=1080)
{
    SDL_Init( SDL_INIT_VIDEO );

    SDL_WindowFlags windowFlags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowExtent.width, _windowExtent.height, windowFlags);

    this->_isInitialized = true;
}

void GameEngine::CleanUp()
{
    if(this->_isInitialized)
    {
        SDL_DestroyWindow(_window);
    }
}

/* handle events in each state */
void GameEngine::HandleEvents()
{
    this->states.back()->HandleEvents(this);
}

/* handle Update in each state */
void GameEngine::Update()
{
    this->states.back()->HandleEvents(this);
}

/* draw the graphics of each state */
void GameEngine::Draw()
{
    //nothing yet
    this->states.back()->Draw(this);
}

void GameEngine::ChangeState(GameState* state)
{
    //cleanup the current state
    if( !states.empty() )
    {
        this->states.back()->CleanUp();
        this->states.pop_back();
    }
}

void GameEngine::PushState(GameState* state)
{
    //pause current state
    if( !states.empty() )
    {
        this->states.back()->Pause();
    }

    //store and initialize the new state
    this->states.push_back(state);
    this->states.back()->Init();
}

void GameEngine::PopState()
{
    //clean up currents tate
    if( !this->states.empty() )
    {
        this->states.back()->CleanUp();
        this->states.pop_back();
    }

    //resume previous state
    if( !this->states.empty() )
    {
        this->states.back()->Resume();
    }
}

