#include "BoxCollider.h"
namespace WillieNelson {

    void BoxCollider::start() {
        m_width = 10;
        m_height = 10;
    }

    void BoxCollider::update(float delta_time, std::vector<sf::Event> &events) {

    }

    bool BoxCollider::is_colliding(BoxCollider& other) {
        auto self_left = entity->transform.position.x;
        auto self_bottom = entity->transform.position.y;

        auto other_left = other.entity->transform.position.x;
        auto other_right = other.entity->transform.position.x + m_width;
        auto other_bottom = other.entity->transform.position.y;
        auto other_top = other.entity->transform.position.y + m_height;

       return (self_left >= other_left && self_left <= other_right) &&
                (self_bottom >= other_bottom && self_bottom <= other_top);
    }

    void BoxCollider::set_dimensions(float width, float height) {
        m_height = height;
        m_width = width;
    }
}