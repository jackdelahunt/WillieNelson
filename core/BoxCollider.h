#pragma once

#include "Component.h"

namespace WillieNelson {
    class BoxCollider : public Component {
        void start() override;
        void update(float delta_time, std::vector<sf::Event>& events) override;
        void destroy() {}

        bool is_colliding(BoxCollider& other);
        void set_dimensions(float width, float height);

    private:
        float m_width;
        float m_height;
    };
}


