#include "Entity.h"

namespace wilson {
    Entity::Entity() {
        name = "";
        transform = Transform();
        components = std::vector < std::shared_ptr < Component >> ();
    }

    std::shared_ptr<Entity> Entity::New() {
        return std::make_shared<Entity>();
    }

    void Entity::start() {
        for (auto& c: components) {
            c->start();
        }
    }

    void Entity::update(float delta_time, std::vector<sf::Event>& events) {
        for (auto& c: components) {
            if(c->active)
                c->update(delta_time, events);
        }
    }

    void Entity::Destroy() {
        for(auto& component : components) {
            component->Destroy();
        }
    }
}

