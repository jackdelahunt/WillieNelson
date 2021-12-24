#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"
#include <memory>
#include "Game.h"

namespace WillieNelson {

    class Component;
    class WilsonWrapper;

    class SpriteComponent : public Component, public WilsonWrapper {
    public:
        void start() override;
        void update(float delta_time, std::vector<sf::Event>& events) override;
        void destroy() override {};
        void set_texture(std::shared_ptr<sf::Texture>& texture);
        void set_center(float relative_x, float relative_y);
        sf::Drawable* get_drawable() override;
        sf::Transformable* get_transform() override;

    private:
        sf::Sprite m_sprite;
    };
}