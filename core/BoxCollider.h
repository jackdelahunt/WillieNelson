#pragma once

#include "Component.h"

namespace WillieNelson {

    class BoxCollider : public Component {
    public:
        void start() override;
        void update(float delta_time, std::vector<sf::Event>& events) override;
        void destroy() override;

        std::vector<BoxCollider*> is_colliding();
        void set_dimensions(float width, float height);
        float width() {return m_width; }
        float height() {return m_height; }

    private:
        float m_width;
        float m_height;

    };
}


