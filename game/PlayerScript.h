#pragma once
#include "common.h"

class PlayerScript : public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

private:
    WillieNelson::BoxCollider* m_collider;
};


