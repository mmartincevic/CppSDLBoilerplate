#include "myGame.h"
#include "../SDL/SDLManager.h"
#include <iostream>

void myGame::Start()
{
    m_IsRunning = true;
    std::cout << "Game started!" << std::endl;
}

bool myGame::IsRunning() const
{
    return m_IsRunning;
}

void myGame::Stop()
{
    m_IsRunning = false;
    std::cout << "Game stopped!" << std::endl;
}

void myGame::Update(float deltaTime)
{
    // Add update logic here
}

void myGame::Draw(float deltaTime)
{
    SDLManager::Instance().Clear();
    SDLManager::Instance().Present();
}

void myGame::Init()
{
    // Add game init logic here
    SDLManager::Instance().Init(m_gameParams.gameTitle, m_gameParams.screenWidth, m_gameParams.screenHeight);
}

void myGame::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            Stop();
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {

            }
        }

        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
            case SDLK_w:
                Input().KeyPress(SDL_SCANCODE_UP);
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                Input().KeyPress(SDL_SCANCODE_RIGHT);
                break;
            case SDLK_LEFT:
            case SDLK_a:
                Input().KeyPress(SDL_SCANCODE_LEFT);
                break;
            case SDLK_DOWN:
            case SDLK_s:
                Input().KeyPress(SDL_SCANCODE_DOWN);
                break;
            }
        }


        if (event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
            case SDLK_w:
                Input().KeyRelease(SDL_SCANCODE_UP);
                break;
            case SDLK_RIGHT:
            case SDLK_d:
                Input().KeyRelease(SDL_SCANCODE_RIGHT);
                break;
            case SDLK_LEFT:
            case SDLK_a:
                Input().KeyRelease(SDL_SCANCODE_LEFT);
                break;
            case SDLK_DOWN:
            case SDLK_s:
                Input().KeyRelease(SDL_SCANCODE_DOWN);
                break;
            }
        }
        // Handle other events like keyboard, mouse, etc.
    }
}