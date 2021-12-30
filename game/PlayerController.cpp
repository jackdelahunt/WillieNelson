#include "PlayerController.h"
#include "common.h"
#include "BulletController.h"
#include <iostream>
#include <cmath>

void PlayerController::start() {

    m_shooting_sound = entity->get_component<WillieNelson::SoundComponent>().get();
    m_box_collider = entity->get_component<WillieNelson::BoxCollider>().get();

    m_score_text = WillieNelson::Game::Active()->get_entity_with_name("ui_score_entity")->get_component<WillieNelson::TextComponent>().get();
    m_ammo_text = WillieNelson::Game::Active()->get_entity_with_name("ui_ammo_entity")->get_component<WillieNelson::TextComponent>().get();
    m_health_text = WillieNelson::Game::Active()->get_entity_with_name("ui_health_entity")->get_component<WillieNelson::TextComponent>().get();
    m_round_text = WillieNelson::Game::Active()->get_entity_with_name("ui_round_entity")->get_component<WillieNelson::TextComponent>().get();

    if (m_weapon == nullptr) {
        m_weapon = new Weapon();
    }

    if(m_round_text != nullptr) {
        m_round_text->set_text(std::to_string(m_round));
    }
}

void PlayerController::update(float delta_time, std::vector<sf::Event> &events) {
    movement(events);
    shooting(events);

    if(m_score_text != nullptr) {
        m_score_text->set_text("Score : " + std::to_string(m_score));
    }

    if(m_health_text != nullptr) {
        int health = (int) round(m_health);
        m_health_text->set_text(std::to_string(health) + "%");
    }

    if(m_round_text != nullptr) {
        m_round_text->set_text(std::to_string(m_round));
    }

    check_collisions();

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

        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && m_ammo > 0) {
            auto mouse_pos = sf::Mouse::getPosition(WillieNelson::Game::Active()->window());
            auto delta_vector = sf::Vector2f((float)mouse_pos.x - entity->transform.position.x, (float)mouse_pos.y - entity->transform.position.y);
            auto length = std::sqrt(delta_vector.x * delta_vector.x) + std::sqrt(delta_vector.y * delta_vector.y);
            auto normal_vector = delta_vector / length;

            if(m_shooting_sound) m_shooting_sound->play();

            create_bullet(normal_vector);

            if (m_ammo_text != nullptr) {
                m_ammo_text->set_text("Ammo : " + std::to_string(--m_ammo));
            }


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
    bullet_controller->set_damage(m_weapon->weapon_damage);
    box_collder->set_dimensions(15, 15);
    bullet_entity->add_component<WillieNelson::SpriteComponent>()->set_texture(bullet_texture);
    bullet_entity->transform.position = entity->transform.position;
    bullet_entity->transform.scale = sf::Vector2f(0.15f, 0.15f);
    bullet_controller->set_angle(angle);

    WillieNelson::Game::Active()->add_entity(bullet_entity);
}

void PlayerController::check_collisions() {
    if(!m_box_collider) return;

    auto collisions = m_box_collider->is_colliding();
    for(auto other: collisions) {
        if (other && other->entity->name == "ammo") {
            WillieNelson::Game::Active()->remove_entity(*(other->entity));
            m_ammo += 20;
            if (m_ammo_text != nullptr) {
                m_ammo_text->set_text("Ammo : " + std::to_string(m_ammo));
            }

        }
    }


}
