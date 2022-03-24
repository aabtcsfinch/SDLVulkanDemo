#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"
#include "Constants.h"
#include "vk_types.h"
#include "GameStates/GameState.h"

class AssetManager;

class Game {
    private:
        bool isRunning;
        SDL_Window *window;
		std::vector<GameState*> states;
    public:
        Game();
        ~Game();
        int ticksLastFrame = 0;
        bool IsRunning() const;
        static SDL_Renderer *renderer;
        static AssetManager* assetManager;
        static SDL_Event event;
        static SDL_Rect camera;
		VkExtent2D _windowExtent{WINDOW_WIDTH, WINDOW_HEIGHT};
        void LoadLevel(int levelNumber);
        void Initialize(const char* title, int width, int height);
		void CleanUp();

        void ProcessInput();
        void Update();
        void Render();
        
		/* game state functionality */
		void ChangeState(GameState* state);
		void PushState(GameState* state);
		void PopState();

        
		void HandleCameraMovement();
};

#endif
