#include "StateGame.h"
#include "../../../helpers/SDL/SDLManager.h"
#include "../../../project/Sources/definitions.h"
#include "../../../project/Sources/functions.h"
#include <iostream>

void StateGame::Enter(StateManager* manager)
{
    std::cout << "State game enter" << '\n';
    // Entering this gamestate
}

void StateGame::Update(StateManager* manager)
{
    // Do some updating in your game
}

void StateGame::Draw(StateManager* manager)
{
    DrawSomething();
}

void StateGame::Exit(StateManager* manager) 
{
    // Cleanup on exit this state
}

void StateGame::Toggle(StateManager* manager) {}


void StateGame::DrawSomething()
{
    char buffer[50];
    std::sprintf(buffer, "SCORE: %d", randomIntInRange(2, 100));

    SDL_Color color = { 123, 123, 123, 255 };
    SDL_Texture* textTexture = SDLManager::Instance().renderText(buffer, color);

    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
    SDL_Rect destRect = { 10, 70, textWidth, textHeight };  // Position at (100, 100)
    SDL_RenderCopy(SDLManager::Instance().Renderer(), textTexture, nullptr, &destRect);
}
