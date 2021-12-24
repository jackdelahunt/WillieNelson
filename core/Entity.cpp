#include "Entity.h"
#include "BoxCollider.h"
#include "Physics.h"

namespace WillieNelson {
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
            component->destroy();
        }
    }

    void Entity::resolve_physics(std::shared_ptr<Component>& component) {
        if (auto b = dynamic_cast<BoxCollider*>(component.get()))
        {
            Physics::Current()->add_collider(std::static_pointer_cast<BoxCollider>(component));
        }
    }
}

