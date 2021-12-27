#include "PlayerController.h"
#include "common.h"
#include <iostream>
#include <math.h>

void PlayerController::start() {
}

void PlayerController::update(float delta_time, std::vector<sf::Event> &events) {
    movement(events);
    shooting();
}

void PlayerController::movement(std::vector<sf::Event> &events) {
    for (auto& event : events) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::W:
                    entity->transform.position += sf::Vector2f(0, -m_speed);
                    break;
                case sf::Keyboard::A:
                    entity->transform.position += sf::Vector2f(-m_speed, 0);
                    break;
                case sf::Keyboard::S:
                    entity->transform.position += sf::Vector2f(0, m_speed);
                    break;
                case sf::Keyboard::D:
                    entity->transform.position += sf::Vector2f(m_speed, 0);
                    break;
            }
        }
    }
}

void PlayerController::shooting() {
    auto mouse_pos = sf::Mouse::getPosition(WillieNelson::Game::Active()->window());
    auto delta_vector = sf::Vector2f((float)mouse_pos.x - entity->transform.position.x, (float)mouse_pos.y - entity->transform.position.y);
    auto length = std::sqrt(delta_vector.x * delta_vector.x) + std::sqrt(delta_vector.y * delta_vector.y);
    auto normal_vector = delta_vector / length;

    entity->transform.position += (normal_vector * m_speed);
}
