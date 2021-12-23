#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"
#include <memory>
#include "Window.h"


namespace WillieNelson {

    class Component;
    class WilsonWrapper;

    class TextComponent : public Component, public WilsonWrapper {

    public:
        void start() override;
        void update(float delta_time, std::vector<sf::Event>& events) override;
        void destroy() override {};
        //std::shared_ptr<sf::Font>& font
        void set_font();
        //std::shared_ptr<sf::Text>& text
        void set_text();

        sf::Drawable* get_drawable() override;
        sf::Transformable* get_transform() override;


    private:
        sf::Font m_font;
        sf::Text m_text;

    };


}
