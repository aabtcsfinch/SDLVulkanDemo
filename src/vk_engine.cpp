#include "vk_engine.h"
#include "../libs/SDL2/include/SDL.h"
#include "../libs/SDL2/include/SDL_vulkan.h"
#include "vk_types.h"
#include "vk_initializers.h"

void VulkanEngine::init()
{
    SDL_Init( SDL_INIT_VIDEO );

    SDL_WindowFlags windowFlags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

    _window = SDL_CreateWindow("Vulkan Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowExtent.width, _windowExtent.height, windowFlags);

    this->_isInitialized = true;
}

void VulkanEngine::cleanup()
{
    if(this->_isInitialized)
    {
        SDL_DestroyWindow(_window);
    }
}

void VulkanEngine::draw()
{
    //nothing yet
}

void VulkanEngine::run()
{
    SDL_Event e;
    bool isRunning = true;

    while(isRunning)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }
    }
}