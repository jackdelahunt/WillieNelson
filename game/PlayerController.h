#pragma once
#include "common.h"

class PlayerController : public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

private:
    float m_speed = 10.0f;
    WillieNelson::SoundComponent* m_shooting_sound = nullptr;

    void movement(std::vector<sf::Event> &events);
    void shooting(std::vector<sf::Event> &events);
    void create_bullet(sf::Vector2f angle);
};


