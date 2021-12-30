#pragma once
#include "common.h"
#include "PlayerController.h"

class Spawner : public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

    float m_interval = 0.8f;
    int m_spawn_amount = 2;

    inline static float zombie_damage = 0.001f;
    inline static float zombie_health = 100.0f;
    inline static float zombie_speed = 0.01f;

private:
    PlayerController* m_player = nullptr;
    float m_current_time = 0.0f;

    void spawn_zombie();
    void new_round();
};


