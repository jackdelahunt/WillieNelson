#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"
#include <memory>
#include "Game.h"

namespace WillieNelson {

    class Component;
    class WilsonWrapper;

    class ButtonComponent : public Component {

    public:

        void start() override;
        void update(float delta_time, std::vector<sf::Event>& events) override;
        void destroy() override {};

        void set_button(int width, int height, int xPos, int yPos);
        void get_button_click(std::vector<sf::Event> &events);
        void send_call_back(std::function<void()> callback);

    private:
        sf::Vector2i m_button_pos;
        sf::Vector2i m_button_size;
        std::function<void()> m_callback;
    };
}




