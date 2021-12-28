#pragma once

#include "BoxCollider.h"

namespace WillieNelson {
    class Physics {
    public:
        static Physics* Current();

        Physics();
        void add_collider(std::shared_ptr<BoxCollider> collider);
        BoxCollider* is_colliding(BoxCollider& collider);
        void clear();

    private:
        std::vector<std::shared_ptr<BoxCollider>> m_colliders;
        bool are_colliding(BoxCollider& a, BoxCollider& b);
    };

    static Physics* current_physics = nullptr;
}


