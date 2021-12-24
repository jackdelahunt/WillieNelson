#pragma once

#include "BoxCollider.h"

namespace WillieNelson {
    class Physics {
    public:
        static Physics* Current();

        Physics();
        void add_collider(std::shared_ptr<BoxCollider> collider);
        BoxCollider* is_colliding(BoxCollider& collider);

    private:
        std::vector<std::shared_ptr<BoxCollider>> m_colliders;

        bool are_colliding(BoxCollider& left, BoxCollider& right);
    };

    static Physics* current_physics = nullptr;
}

