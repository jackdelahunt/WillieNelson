#include "PlayerScript.h"
#include "common.h"
#include <iostream>

void PlayerScript::start() {
    m_collider = entity->get_component<WillieNelson::BoxCollider>().get();
}

void PlayerScript::update(float delta_time, std::vector<sf::Event> &events) {
    if(!m_collider) return;

    auto mouse_pos = sf::Mouse::getPosition(WillieNelson::Game::Active()->window());
    entity->transform.position = sf::Vector2f(mouse_pos.x, mouse_pos.y);

    if(m_collider->is_colliding() != nullptr) {
        std::cout << "collide";
    }
}
