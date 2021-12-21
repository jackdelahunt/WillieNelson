#pragma once
#include "Window.h"

namespace WillieNelson {
    class Window;

    class Scene {
    public:
        virtual void attach(Window& window) = 0;
    };
}


