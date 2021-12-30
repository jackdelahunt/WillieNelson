#pragma once
#include "common.h"
#include "PlayerController.h"

class ZombieController: public WillieNelson::Component{
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

    inline static float zombie_damage = 0.001f;
    inline static float zombie_health = 100.0f;
    inline static float zombie_speed = 0.01f;

    //void set();

private:
    PlayerController* m_player = nullptr;
    WillieNelson::BoxCollider* m_box_collider = nullptr;
    WillieNelson::SoundComponent* m_dead_sound = nullptr;
    bool m_is_dead = false;

    void check_collisions();
    void drop_loot();
};


