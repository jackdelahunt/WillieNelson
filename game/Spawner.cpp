#include <iostream>
#include "Spawner.h"
#include "ZombieController.h"
#include <stdlib.h>
#include <time.h>

void Spawner::start() {
    srand(time(NULL));
}

void Spawner::update(float delta_time, std::vector<sf::Event> &events) {
    m_current_time += delta_time;
    if(m_current_time >= m_interval) {
        m_current_time = 0;
        spawn_zombie();
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
    zombie_entity->add_component<ZombieController>();
    sprite->set_texture(texture);

    int result = 1 + (rand() % 4);

    std::cout << result << std::endl;

    switch(result) {
        case 1:
            zombie_entity->transform.position = sf::Vector2f((float) WillieNelson::Game::Active()->window().getSize().x + 5, (float) WillieNelson::Game::Active()->window().getSize().y + 5);
            break;
        case 2:
            zombie_entity->transform.position = sf::Vector2f((float) - 5, (float) - - 5);
            break;
        case 3:
            zombie_entity->transform.position = sf::Vector2f((float) - 5, (float) WillieNelson::Game::Active()->window().getSize().y + 5);
            break;
        case 4:
            zombie_entity->transform.position = sf::Vector2f((float) WillieNelson::Game::Active()->window().getSize().x + 5, (float) - 5);
            break;
        default:
            zombie_entity->transform.position = sf::Vector2f((float) WillieNelson::Game::Active()->window().getSize().x + 5, (float) WillieNelson::Game::Active()->window().getSize().y + 5);
    }

    WillieNelson::Game::Active()->add_entity(zombie_entity);

}
