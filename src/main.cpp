#include "GameEngine.h"
#include "SplashScreen.h"

int main()
{
    GameEngine g;

    g.Init("SDL Vulkan Turn-Based Strategy Game v1.0");
    g.ChangeState(SplashScreen::Instance());

    while( g.IsRunning() )
    {
        g.HandleEvents();
        g.Update();
        g.Draw();
    }
    
    //cleanup the engine
    g.CleanUp();
    return 0;
}