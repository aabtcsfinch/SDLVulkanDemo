#include "Game.h"
#include "SplashScreen.h"

int main()
{
    Game g;

    g.Initialize("SDL Vulkan Turn-Based Strategy Game v1.0");
    g.ChangeState(SplashScreen::Instance());

    while( g.IsRunning() )
    {
        g.ProcessInput();
        g.Update();
        g.Draw();
    }
    
    //cleanup the engine
    g.CleanUp();
    return 0;
}