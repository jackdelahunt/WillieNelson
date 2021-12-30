#include "BulletController.h"
#include <iostream>

void BulletController::start() {
    std::cout << "Create bullet";
}

void BulletController::update(float delta_time, std::vector<sf::Event> &events) {
    entity->transform.position += m_angle * m_speed;
}

void BulletController::set_damage(float damage) {
    m_damage = damage;
}

void BulletController::set_angle(sf::Vector2f angle) {
    m_angle = angle;
}

