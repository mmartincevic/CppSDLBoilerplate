#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#undef main

#include "../helpers/Game/myGame.h"

myGame* game;

int main(int argc, const char* args[])
{
    myGameParams gameParam;
    gameParam.screenWidth = 1024;
    gameParam.screenHeight = 800;
    gameParam.gameTitle = "MOJ TITLE";
    game = new myGame(gameParam);
    game->Init();
    game->Start();

    while (game->IsRunning())
    {
        game->handleEvents();
        game->Update(SDL_GetTicks64());
        game->Draw(SDL_GetTicks64());
    }

    delete game;
    return 1;
}