
#include <iostream>
#include "ButtonComponent.h"

namespace WillieNelson {

    void ButtonComponent::start() {}

    void ButtonComponent::update(float delta_time, std::vector<sf::Event>& events) {
        get_button_click(events);
    }

    void ButtonComponent::set_button(int width, int height, int xPos, int yPos) {
        m_button_pos = sf::Vector2i(xPos, yPos);
        m_button_size = sf::Vector2i(width,height);
    }

    void ButtonComponent::send_call_back(std::function<void()> callback) {
        m_callback = callback;
    }

    void ButtonComponent::get_button_click(std::vector<sf::Event> &events) {
        for (auto& event : events) {
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

                auto mousePos = sf::Mouse::getPosition(WillieNelson::Game::Active()->window());

                if (mousePos.x >= m_button_pos.x && mousePos.x <= m_button_pos.x + m_button_size.x &&
                mousePos.y >= m_button_pos.y && mousePos.y <= m_button_pos.y + m_button_size.y) {
                    m_callback();
                    //std::cout << "Button Pressed" << std::endl;
                }
            }
        }


    }
}