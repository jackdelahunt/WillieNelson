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

    void Physics::remove_collider(BoxCollider &collider) {
        int index = -1;
        for(int i = 0; i < m_colliders.size(); i++) {
            if(m_colliders.at(i).get() == &collider) {
                index = i;
                break;
            }
        }

        if(index < 0) return;

        auto iter = m_colliders.begin() + index;
        m_colliders.erase(iter);
    }

    std::vector<BoxCollider*> Physics::is_colliding(BoxCollider &collider) {
        auto colliding_with = std::vector<BoxCollider*>();
        for (auto& col : m_colliders) {
            if(col.get() == &collider) continue;

            if(are_colliding(*col, collider)) {
                colliding_with.push_back(col.get());
            }

        }
        return colliding_with;
    }

    void Physics::clear() {
        m_colliders.clear();
    }

    bool Physics::are_colliding(BoxCollider& a, BoxCollider& b) {
        auto a_min_x = a.entity->transform.position.x;
        auto a_max_x = a.entity->transform.position.x + a.width();
        auto a_min_y = a.entity->transform.position.y;
        auto a_max_y = a.entity->transform.position.y + a.height();

        auto b_min_x = b.entity->transform.position.x;
        auto b_max_x = b.entity->transform.position.x + a.width();
        auto b_min_y = b.entity->transform.position.y;
        auto b_max_y = b.entity->transform.position.y + a.height();

        return (
        (a_min_x <= b_max_x && a_max_x >= b_min_x) &&
        (a_min_y <= b_max_y && a_max_y >= b_min_y)
        );
    }
}
