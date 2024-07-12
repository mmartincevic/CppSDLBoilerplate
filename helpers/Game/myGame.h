#pragma once

#include "../Input/SimpleInputManager.h"

typedef struct myGameParams
{
    int screenWidth;
    int screenHeight;
    const char* gameTitle;
} myGameParams;


class myGame
{
public:
    myGame(myGameParams& params) : m_gameParams(params), m_IsRunning(false) {}
    ~myGame() = default;

    void Start();
    void Stop();
    bool IsRunning() const;

    void Update(float deltaTime);
    void Draw(float deltaTime);
    void Init();

    [[nodiscard]] inline SimpleInputManager& Input() { return m_InputManager; }

    void handleEvents();


private:
    SimpleInputManager  m_InputManager;
    myGameParams        m_gameParams;
    bool                m_IsRunning;
};