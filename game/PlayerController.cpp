#include "PlayerController.h"
#include "common.h"
#include <iostream>

void PlayerController::start() {
}

void PlayerController::update(float delta_time, std::vector<sf::Event> &events) {
    for (auto& event : events) {
        if(event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::W:
                    entity->transform.position += sf::Vector2f(0, -m_speed); break;
                case sf::Keyboard::A:
                    entity->transform.position += sf::Vector2f(-m_speed, 0); break;
                case sf::Keyboard::S:
                    entity->transform.position += sf::Vector2f(0, m_speed); break;
                case sf::Keyboard::D:
                    entity->transform.position += sf::Vector2f(m_speed, 0); break;
            }
        }
    }
}
