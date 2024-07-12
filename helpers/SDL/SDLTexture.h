#pragma once
#include <SDL.h>
#include <string>
#include <unordered_map>
#include <memory>

class SDLTexture
{
public:
    SDLTexture(SDL_Texture* texture);
    ~SDLTexture();
    SDL_Texture* Get() const { return m_texture; }

private:
    SDL_Texture* m_texture;
};