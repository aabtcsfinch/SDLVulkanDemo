#ifndef GAME_H
#define GAME_H

#include "vk_types.h"
#include "GameState.h"
#include <vector>

class Game 
{
	public:
		Game();
		~Game();
		bool _isInitialized{ false };
		int _frameNumber {0};
		static SDL_Renderer* renderer;	
		static SDL_Event event;
		VkExtent2D _windowExtent{ 1920 , 1080 };
		void Initialize(const char* title, int width=1920, int height=1080);
		void CleanUp();
		void ChangeState(GameState* state);
		void PushState(GameState* state);
		void PopState();
		bool IsRunning() const;
		void Quit() { isRunning = false; }
		void ProcessInput();
		void Update();
		void Draw();
		void Run();

	private:
		bool isRunning;
		std::vector<GameState*> states;
		SDL_WindowFlags windowFlags;
		SDL_Window *window;
};
#endif