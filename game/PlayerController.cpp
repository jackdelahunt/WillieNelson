#include "PlayerController.h"
#include "common.h"
#include "BulletController.h"
#include <iostream>
#include <math.h>

void PlayerController::start() {
    m_shooting_sound = entity->get_component<SoundComponent>().get();
}

void PlayerController::update(float delta_time, std::vector<sf::Event> &events) {
    movement(events);
    shooting(events);
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

void PlayerController::shooting(std::vector<sf::Event> &events) {
    for (auto& event : events) {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            auto mouse_pos = sf::Mouse::getPosition(WillieNelson::Game::Active()->window());
            auto delta_vector = sf::Vector2f((float)mouse_pos.x - entity->transform.position.x, (float)mouse_pos.y - entity->transform.position.y);
            auto length = std::sqrt(delta_vector.x * delta_vector.x) + std::sqrt(delta_vector.y * delta_vector.y);
            auto normal_vector = delta_vector / length;

            if(m_shooting_sound) m_shooting_sound->play();
            create_bullet(normal_vector);
        } else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
            WillieNelson::Game::Active()->next_scene();
        }
    }
}

void PlayerController::create_bullet(sf::Vector2f angle) {
    auto bullet_entity = WillieNelson::Entity::New();
    bullet_entity->name = "bullet";
    auto bullet_controller = bullet_entity->add_component<BulletController>();
    auto bullet_texture = WillieNelson::Resources::Current()->load_texture("./resources/battle-location-top-down-game-tileset-pack/PNG/Props/Artifact.png");
    auto box_collder = bullet_entity->add_component<WillieNelson::BoxCollider>();
    box_collder->set_dimensions(15, 15);
    bullet_entity->add_component<WillieNelson::SpriteComponent>()->set_texture(bullet_texture);
    bullet_entity->transform.position = entity->transform.position;
    bullet_entity->transform.scale = sf::Vector2f(0.15f, 0.15f);
    bullet_controller->set_angle(angle);

    WillieNelson::Game::Active()->add_entity(bullet_entity);
}
