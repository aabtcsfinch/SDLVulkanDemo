#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "vk_types.h"
#include "GameState.h"
#include <vector>

class GameEngine 
{
	public:

		bool _isInitialized{ false };
		int _frameNumber {0};

		VkExtent2D _windowExtent{ 1920 , 1080 };

		//initializes everything in the engine
		void Init(const char* title, int width=1920, int height=1080);
		void CleanUp();

		void ChangeState(GameState* state);
		void PushState(GameState* state);
		void PopState();

		/* check to see if we're still running */
		bool IsRunning() { return isRunning; }
		void Quit() { isRunning = false; }
		/* handle events */
		void HandleEvents();
		/* update loop */
		void Update();
		//draw loop
		void Draw();

		//run main loop
		void Run();

		SDL_Renderer* renderer;

	private:
		bool isRunning;
		std::vector<GameState*> states;
		SDL_WindowFlags windowFlags;
		SDL_Renderer* render;
		SDL_Window* window;
};
#endif