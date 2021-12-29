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
    float m_speed = 0.01f;

    void check_collisions();
};

