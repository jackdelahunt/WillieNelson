#include "BoxCollider.h"
#include "Physics.h"

namespace WillieNelson {

    void BoxCollider::start() {}

    void BoxCollider::update(float delta_time, std::vector<sf::Event> &events) {

    }   

    BoxCollider* BoxCollider::is_colliding() {
        return Physics::Current()->is_colliding(*this);
    }

    void BoxCollider::set_dimensions(float width, float height) {
        m_height = height;
        m_width = width;
    }
}