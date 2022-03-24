#include <iostream>
#include "Game.h"
#include "../libs/SDL2/include/SDL.h"
#include "../libs/SDL2/include/SDL_vulkan.h"
#include "vk_types.h"
#include "vk_initializers.h"

SDL_Renderer* Game::renderer;
Game::Game()
{
    this->isRunning = false;
}

Game::~Game()
{

}

bool Game::IsRunning() const
{
    return this->isRunning;
}

void Game::Initialize(const char* title, int width=1920, int height=1080)
{
    SDL_Init( SDL_INIT_VIDEO );
    /* set window flag for vulkan create window and renderer */
    this->windowFlags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowExtent.width, _windowExtent.height, this->windowFlags);
    renderer = SDL_CreateRenderer( this->window, -1, 0 );
    if ( !renderer )
    {
        std::cerr << "Error creating the SDL renderer." << std::endl;
    }
    this->_isInitialized = true;
    this->isRunning = true;
    return;
}

void Game::CleanUp()
{
    if(this->_isInitialized)
    {
        SDL_DestroyWindow(this->window);
    }
}

/* Process the input for each state */
void Game::ProccessInput()
{
    this->states.back()->ProccessInput(this);
}

/* handle Update in each state */
void Game::Update()
{
    this->states.back()->ProcessInput(this);
}

/* draw the graphics of each state */
void Game::Draw()
{
    //nothing yet
    this->states.back()->Draw(this);
}

void Game::ChangeState(GameState* state)
{
    //cleanup the current state
    if( !states.empty() )
    {
        this->states.back()->CleanUp();
        this->states.pop_back();
    }
}

void Game::PushState(GameState* state)
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

void Game::PopState()
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

