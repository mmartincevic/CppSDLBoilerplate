// SDLManager.h
#pragma once
#include <SDL.h>
#include <string>
#include <unordered_map>
#include <memory>
#include "SDLTexture.h"

class SDLManager
{
public:
    static SDLManager& Instance();

    bool Init(const std::string& title, int width, int height);
    void Cleanup();

    bool LoadTexture(const std::string& id, const std::string& path);
    SDLTexture* GetTexture(const std::string& id);

    SDL_Renderer* Renderer() const { return m_renderer; }
    SDL_Window* Window() const { return m_window; }

    void Clear();
    void Present();
    bool HandleEvents();

private:
    SDLManager();
    ~SDLManager();
    SDLManager(const SDLManager&) = delete;
    SDLManager& operator=(const SDLManager&) = delete;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    std::unordered_map<std::string, std::unique_ptr<SDLTexture>> m_textures;
    bool m_quit;
};