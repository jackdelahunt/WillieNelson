#include <iostream>
#include "ZombieController.h"


void ZombieController::start() {
    m_player = WillieNelson::Game::Active()->get_entity_with_name("player")->get_component<PlayerController>().get();
}

void ZombieController::update(float delta_time, std::vector<sf::Event> &events) {
    if(!m_player) return;

    auto player_pos = m_player->entity->transform.position;
    auto delta_vector = player_pos - entity->transform.position;
    auto length = std::sqrt(delta_vector.x * delta_vector.x) + std::sqrt(delta_vector.y * delta_vector.y);
    auto normal_vector = delta_vector / length;

    entity->transform.position += normal_vector * m_speed;
}
