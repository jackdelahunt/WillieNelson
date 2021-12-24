#pragma once
#include "Game.h"

namespace WillieNelson {
    class Game;

    class Scene {
    public:
        virtual void attach(Game& window) = 0;
    };
}


