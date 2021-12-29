#pragma once
#include "common.h"
#include "PlayerController.h"

class ZombieController: public WillieNelson::Component{
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

private:
    PlayerController* m_player = nullptr;
    WillieNelson::BoxCollider* m_box_collider = nullptr;
    WillieNelson::SoundComponent* m_dead_sound = nullptr;
    bool m_is_dead = false;
    float m_speed = 0.01f;
    float m_damage = 0.001f;

    void check_collisions();
};


