#pragma once
#include "common.h"

class BulletController: public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;
    void set_angle(sf::Vector2f angle);

private:
    sf::Vector2f m_angle;
    float m_speed = 1.0f;
};