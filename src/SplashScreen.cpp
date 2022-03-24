#include <stdio.h>
#include <iostream>
#include "../libs/SDL2/include/SDL.h"
#include "Game.h"
#include "GameState.h"
#include "SplashScreen.h"
#include "MenuState.h"

SplashScreen SplashScreen::instance;

void SplashScreen::Init()
{
    std::cout << "We're at the Splash Screen of the game!" <<std::endl;
}

void SplashScreen::CleanUp()
{
    std::cout<< "We're at the splash screen cleanup phase" <<std::endl;
}

void SplashScreen::Pause()
{
    std::cout<< "We're at the pause phase of the splash screen" <<std::endl;
}

void SplashScreen::Resume()
{
    std::cout<< "We;re at the resume phase of the splash screen" << std::endl;
}

void SplashScreen::ProccessInput(Game* game)
{
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_SPACE:
						game->ChangeState( MenuState::Instance() );
						break;

					case SDLK_ESCAPE:
						game->Quit();
						break;
				}
				break;
		}
	}
}

void SplashScreen::Update(Game* game)
{

}

void SplashScreen::Draw(Game* game)
{
    /* draw stuff here */
}
