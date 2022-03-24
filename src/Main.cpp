#include <iostream>
#include "./Constants.h"
#include "./Game.h"

int main(int argc, char *args[]) {
    Game game;

    game.Initialize("SDL Vulkan Turn Based Strategy Game V1.0", WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game.IsRunning() ) 
    {
        game.ProcessInput();
        game.Update();
        game.Render();
    }

    game.CleanUp();

    return 0;
}
