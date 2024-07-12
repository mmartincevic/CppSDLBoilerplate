/*
*           ___            __    ___  __    ___       _ _                 _       _        
*          / __\ __  _ __ / _\  /   \/ /   / __\ ___ (_) | ___ _ __ _ __ | | __ _| |_ ___  
*         / / | '_ \| '_ \\ \  / /\ / /   /__\/// _ \| | |/ _ \ '__| '_ \| |/ _` | __/ _ \ 
*        / /__| |_) | |_) |\ \/ /_// /___/ \/  \ (_) | | |  __/ |  | |_) | | (_| | ||  __/ 
*        \____/ .__/| .__/\__/___,'\____/\_____/\___/|_|_|\___|_|  | .__/|_|\__,_|\__\___| 
*             |_|   |_|                                            |_|                     
*
* Created by:   djomla
* Updated by:   djomla
*/


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