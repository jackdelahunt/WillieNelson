#include "BulletController.h"
#include <iostream>

void BulletController::start() {
    //std::cout << "Create bullet";
}

void BulletController::update(float delta_time, std::vector<sf::Event> &events) {
    entity->transform.position += m_angle * m_speed;

    check_bounds();
}

void BulletController::set_damage(float damage) {
    m_damage = damage;
}

void BulletController::set_angle(sf::Vector2f angle) {
    m_angle = angle;
}

void BulletController::check_bounds() {

    if (entity->transform.position.x < 0 || entity->transform.position.x > WillieNelson::Game::Active()->window().getSize().x ||
            entity->transform.position.y < 0 || entity->transform.position.y > WillieNelson::Game::Active()->window().getSize().y) {

        WillieNelson::Game::Active()->remove_entity(*entity);
    }


}

