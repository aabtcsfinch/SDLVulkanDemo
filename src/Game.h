#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"
#include "Constants.h"
#include "vk_types.h"

class AssetManager;

class Game {
    private:
        bool isRunning;
        SDL_Window *window;
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
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
        void HandleCameraMovement();
};

#endif
