#include <iostream>
#include "Spawner.h"
#include "ZombieController.h"
#include "PlayerController.h"
#include <stdlib.h>
#include <ctime>

void Spawner::start() {
    srand(time(nullptr));
    m_player = WillieNelson::Game::Active()->get_entity_with_name("player")->get_component<PlayerController>().get();
}

void Spawner::update(float delta_time, std::vector<sf::Event> &events) {
    m_current_time += delta_time;

    if(m_current_time >= m_interval && m_spawn_amount > 0) {
        m_current_time = 0;
        m_spawn_amount--;
        spawn_zombie();

    }

    if(m_spawn_amount == 0) {
        new_round();
    }
}

void Spawner::new_round() {
    auto zombies = WillieNelson::Game::Active()->get_entity_with_name("zombie");

    // If zombie is null then all zombies are dead increase the next wave difficulty
    if(zombies == nullptr) {
        m_player->m_round++;

        zombie_speed += 0.002f;
        zombie_damage += 0.0002f;
        zombie_health += 0.2f;

        m_spawn_amount = (int) round(30 * (m_player->m_round * 0.15));

        if (m_player->m_round % 5 == 0) {
            WillieNelson::Game::Active()->next_scene();
        }
    }

}

void Spawner::spawn_zombie() {

    srand((unsigned) time(nullptr));
    auto texture = WillieNelson::Resources::Current()->load_texture("./resources/bk_player_assets/player_hk_stand.png");
    auto sound = WillieNelson::Resources::Current()->load_sound("./resources/sounds/dead.wav");
    auto zombie_entity = WillieNelson::Entity::New();
    auto sprite = zombie_entity->add_component<WillieNelson::SpriteComponent>();
    auto box_collider = zombie_entity->add_component<WillieNelson::BoxCollider>();
    zombie_entity->add_component<WillieNelson::SoundComponent>()->set_sound(sound);
    box_collider->set_dimensions(25, 25);
    auto zombie_controller = zombie_entity->add_component<ZombieController>();
    //zombie_entity->add_component<ZombieController>();
    zombie_controller->set_attributes(zombie_health, zombie_speed, zombie_damage);
    sprite->set_texture(texture);
    zombie_entity->name = "zombie";

    int result = 1 + (rand() % 4);

    switch(result) {
        case 1:
            zombie_entity->transform.position = sf::Vector2f((float) WillieNelson::Game::Active()->window().getSize().x + 5, (float) WillieNelson::Game::Active()->window().getSize().y + 5);
            break;
        case 2:
            zombie_entity->transform.position = sf::Vector2f((float) - 10, (float) - 10);
            break;
        case 3:
            zombie_entity->transform.position = sf::Vector2f((float) - 10, (float) WillieNelson::Game::Active()->window().getSize().y + 10);
            break;
        case 4:
            zombie_entity->transform.position = sf::Vector2f((float) WillieNelson::Game::Active()->window().getSize().x + 10, (float) - 10);
            break;
        default:
            zombie_entity->transform.position = sf::Vector2f((float) WillieNelson::Game::Active()->window().getSize().x + 10, (float) WillieNelson::Game::Active()->window().getSize().y + 5);
    }

    WillieNelson::Game::Active()->add_entity(zombie_entity);

}

