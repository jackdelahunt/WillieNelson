#pragma once
#include "common.h"

class Spawner : public WillieNelson::Component {
public:
    void start() override;
    void update(float delta_time, std::vector<sf::Event> &events) override;

private:
    float m_interval = 0.5f;
    float m_current_time = 0.0f;
    float spawn_area = 100.0f;

    void spawn_zombie();
};


