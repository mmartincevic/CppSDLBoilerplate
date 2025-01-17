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

#pragma once

#include "../Input/SimpleInputManager.h"
#include "../project/Sources/Vector2.h"
#include "State/StateManager.h"

typedef struct myGameParams
{
    int screenWidth;
    int screenHeight;
    const char* gameTitle;
} myGameParams;


class myGame
{
public:
    myGame(myGameParams& params) : m_gameParams(params), m_IsRunning(false)
    {
        m_StateManager = new StateManager();
    }
    ~myGame();

    void Start();
    void Stop();
    bool IsRunning() const;

    void Update(float deltaTime);
    void Draw(float deltaTime);
    void Clear();
    void Init();

    void handleEvents();

private:
    myGameParams        m_gameParams;
    StateManager*       m_StateManager;

    bool                m_IsRunning;
};