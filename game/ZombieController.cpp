#include <iostream>
#include "ZombieController.h"


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

void ZombieController::check_collisions() {
    if(!m_box_collider) return;

    auto collisions = m_box_collider->is_colliding();
    for(auto other : collisions) {
        if (other && other->entity->name == "bullet") {

            if(m_dead_sound) m_dead_sound->play();
            m_is_dead = true;
            m_player->m_score += 10;
            return;
        }
    }
}
