#pragma once
#include "common.h"

class PlayerController : public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

private:
    float m_speed = 10.0f;
};


