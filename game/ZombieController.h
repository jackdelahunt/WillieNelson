#pragma once
#include "common.h"
#include "PlayerController.h"
#include "BulletController.h"

class ZombieController: public WillieNelson::Component{
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;
    void set_attributes(float health, float speed, float damage);



    //void set();

private:
    float m_health = 100.0f;
    float m_speed =  0.01f;
    float m_damage = 0.001f;


    BulletController* m_bullet = nullptr;
    PlayerController* m_player = nullptr;
    WillieNelson::BoxCollider* m_box_collider = nullptr;
    WillieNelson::SoundComponent* m_dead_sound = nullptr;
    bool m_is_dead = false;

    void check_collisions();
    void drop_loot();
};


