#include "Physics.h"
namespace WillieNelson {

    Physics *Physics::Current() {
        if(current_physics == nullptr)
            current_physics = new Physics();

        return current_physics;
    }

    Physics::Physics() {
        m_colliders = std::vector<std::shared_ptr<BoxCollider>>();
    }

    void Physics::add_collider(std::shared_ptr<BoxCollider> collider) {
        m_colliders.push_back(collider);
    }

    BoxCollider *Physics::is_colliding(BoxCollider &collider) {
        for (auto& col : m_colliders) {
            if(col.get() == &collider) continue;

            if(are_colliding(*col, collider)) {
                return col.get();
            }

        }
        return nullptr;
    }

    void Physics::clear() {
        m_colliders.clear();
    }

    bool Physics::are_colliding(BoxCollider& left, BoxCollider& right) {
        auto left_left = left.entity->transform.position.x;
        auto left_bottom = left.entity->transform.position.y;

        auto other_left = right.entity->transform.position.x;
        auto other_right = right.entity->transform.position.x + right.width();
        auto other_bottom = right.entity->transform.position.y;
        auto other_top = right.entity->transform.position.y + right.height();

        return (left_left >= other_left && left_left <= other_right) &&
               (left_bottom >= other_bottom && left_bottom <= other_top);
    }
}
