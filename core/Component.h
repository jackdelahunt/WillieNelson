#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"

namespace WillieNelson {
    class Entity;

    class Component {
    public:
        bool active = true;
        Entity* entity = nullptr;

        virtual void start() = 0;
        virtual void update(float delta_time, std::vector<sf::Event>& events) = 0;
        virtual void destroy() {}
    };
}