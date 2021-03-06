#include <iostream>
#include "ZombieController.h"
#include <ctime>


void ZombieController::start() {
    m_player = WillieNelson::Game::Active()->get_entity_with_name("player")->get_component<PlayerController>().get();
    m_box_collider = entity->get_component<WillieNelson::BoxCollider>().get();
    m_dead_sound = entity->get_component<WillieNelson::SoundComponent>().get();
}

void ZombieController::update(float delta_time, std::vector<sf::Event> &events) {

    if(m_is_dead) {
        if(!m_dead_sound->is_playing()) {
            WillieNelson::Game::Active()->remove_entity(*entity);
        }

        return;
    }

    check_collisions();

    if(!m_player) return;

    auto player_pos = m_player->entity->transform.position;
    auto delta_vector = player_pos - entity->transform.position;
    auto length = std::sqrt(delta_vector.x * delta_vector.x) + std::sqrt(delta_vector.y * delta_vector.y);
    auto normal_vector = delta_vector / length;

    entity->transform.position += normal_vector * m_speed;
}

void ZombieController::set_attributes(float health, float speed, float damage) {
    m_health = health;
    m_speed = speed;
    m_damage = damage;
}

void ZombieController::check_collisions() {
    if(!m_box_collider) return;

    auto collisions = m_box_collider->is_colliding();
    for(auto other : collisions) {
        if (other && other->entity->name == "bullet") {
            m_bullet = other->entity->get_component<BulletController>().get();

            m_health -= m_bullet->m_damage;

            WillieNelson::Game::Active()->remove_entity(*(other->entity));

            m_player->m_score += 10;

            if (m_health < 0) {
                std::cout << "dead";
                if(m_dead_sound) m_dead_sound->play();
                m_is_dead = true;

                m_player->m_score += 100;

                drop_loot();
            }


            return;
        }

        if (other && other->entity->name == "player" && m_player->m_health > 0.f) {
            m_player->m_health -= m_damage;
            return;
        }
    }
}

void ZombieController::drop_loot() {
    srand((unsigned) time(nullptr));
    int result = 1 + (rand() % 10); // ammo drop chance
    int result2 = 1 + (rand() % 35); // Gun drop chance
    int gunResult = 1 + (rand() % 17); // Gun variation

    std::cout << "Ammo Chance " << result << std::endl;
    std::cout << "Gun Chance " << result2 << std::endl;

    if (result == 10 || m_player->m_ammo < 4) {
        //Drop Ammo 1 in 20 chance
        auto texture = WillieNelson::Resources::Current()->load_texture("./resources/ammo.png");
        auto ammo_entity = WillieNelson::Entity::New();
        auto sprite = ammo_entity->add_component<WillieNelson::SpriteComponent>();
        auto box_collider = ammo_entity->add_component<WillieNelson::BoxCollider>();
        ammo_entity->name = "ammo";
        box_collider->set_dimensions(25, 25);
        sprite->set_texture(texture);
        ammo_entity->transform.scale = sf::Vector2f(0.05f,0.05f);
        ammo_entity->transform.position = this->entity->transform.position;

        WillieNelson::Game::Active()->add_entity(ammo_entity);

    } else if (result2 == 35) {
        std::string gunPath = "./resources/weapons/tile";
        gunPath = gunPath + std::to_string(gunResult) + ".png";

        //Drop gun 1 in 100 chance
        auto texture = WillieNelson::Resources::Current()->load_texture(gunPath.c_str());
        auto gun_entity = WillieNelson::Entity::New();
        auto sprite = gun_entity->add_component<WillieNelson::SpriteComponent>();
        auto box_collider = gun_entity->add_component<WillieNelson::BoxCollider>();
        gun_entity->name = "gun";
        box_collider->set_dimensions(25, 25);
        sprite->set_texture(texture);
        gun_entity->transform.scale = sf::Vector2f(1.5f,1.5f);
        gun_entity->transform.position = this->entity->transform.position;

        WillieNelson::Game::Active()->add_entity(gun_entity);
    }




}
