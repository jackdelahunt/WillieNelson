#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"
#include <memory>
#include "Game.h"
#include "TextComponent.h"

namespace WillieNelson {

    class Component;
    class WilsonWrapper;

    class ButtonComponent : public Component, public WilsonWrapper {

    public:

//        ButtonComponent(float width, float height, float xPos, float yPos, const TextComponent& text, sf::Color color) {
//            this->shape.setSize(sf::Vector2f(width, height));
//            this->shape.setPosition(sf::Vector2f(xPos, yPos));
//            this->text.set_font("Sansation_Regular");
//            this->text.set_text("Cool Button", sf::Color::Magenta, 100);
//        }

        void start() override;
        void update(float delta_time, std::vector<sf::Event>& events) override;
        void destroy() override {};

        void set_button(float width, float height, float xPos, float yPos);
        //bool get_button_click(); return false;

        sf::Drawable* get_drawable() override;
        sf::Transformable* get_transform() override;


    private:
        sf::RectangleShape m_shape;
        TextComponent m_text;
        sf::Vector2f m_button_pos;
        sf::Vector2f m_button_size;
    };
}




