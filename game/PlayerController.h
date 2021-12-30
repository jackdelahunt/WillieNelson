#pragma once
#include "common.h"

class PlayerController : public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

    int m_score = 0;
    double m_health = 100;
    int m_ammo = 50;
    int m_round = 1;

private:
    float m_speed = 10.0f;
    WillieNelson::SoundComponent* m_shooting_sound = nullptr;


    WillieNelson::TextComponent* m_ammo_text = nullptr;
    WillieNelson::TextComponent* m_score_text = nullptr;
    WillieNelson::TextComponent* m_round_text = nullptr;
    WillieNelson::TextComponent* m_health_text = nullptr;
    WillieNelson::BoxCollider* m_box_collider = nullptr;

    void movement(std::vector<sf::Event> &events);
    void shooting(std::vector<sf::Event> &events);
    void create_bullet(sf::Vector2f angle);
    void check_collisions();
};


