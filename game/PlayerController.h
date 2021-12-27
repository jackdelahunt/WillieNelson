#pragma once
#include "common.h"

class PlayerController : public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

private:
    float m_speed = 0.1f;

    void movement(std::vector<sf::Event> &events);
    void shooting();
};


