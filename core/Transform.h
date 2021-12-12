#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

namespace WillieNelson {
    class Transform {
    public:
        sf::Vector2f position = sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
        float rotation = 0.0f;
    };
}