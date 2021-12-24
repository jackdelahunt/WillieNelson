#include "PlayerScript.h"
#include <iostream>

void PlayerScript::start() {
    m_collider = entity->get_component<WillieNelson::BoxCollider>().get();
}

void PlayerScript::update(float delta_time, std::vector<sf::Event> &events) {
    if(!m_collider) return;

    if(m_collider->is_colliding() != nullptr) {
        std::cout << "collide";
    }
}
