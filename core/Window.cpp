#include "Window.h"

#include <memory>

namespace WillieNelson {
    Window::Window() {
        m_video_mode = sf::VideoMode(800, 640);
        m_window = std::make_unique<sf::RenderWindow>(m_video_mode, "WillieNelson");
    }

    void Window::start() {

        for(auto& entity : m_entities) {
            entity->start();
        }

        sf::Clock delta_clock;
        float delta_time = 0.0f;
        while (m_window->isOpen()) {
            auto events = poll_events();
            update(delta_time, events);
            draw();
            delta_time = delta_clock.restart().asSeconds();
        }
        end();
    }

    void Window::end() {
        for(auto& entity : m_entities) {
            entity->Destroy();
        }
    }

    std::vector<sf::Event> Window::poll_events() {
        auto events = std::vector<sf::Event>();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();

            events.push_back(event);
        }

        return events;
    }

    void Window::draw() {
        m_window->clear();
        for(auto& entity : m_entities) {
            if(!entity->enabled) continue;

            for(auto& component : entity->components) {
                auto wilson_wrapper = std::dynamic_pointer_cast<WilsonWrapper>(component);
                if(wilson_wrapper != nullptr) {
                    auto drawable = wilson_wrapper->get_drawable();
                    auto transformable = wilson_wrapper->get_transform();
                    if(transformable != nullptr) {
                        transformable->setPosition(entity->transform.position);
                        transformable->setScale(entity->transform.scale);
                        transformable->setRotation(entity->transform.rotation);
                    }

                    m_window->draw(*drawable);
                }
            }
        }
        m_window->display();
    }

    void Window::update(float delta_time, std::vector<sf::Event>& events) {
        for(auto& entity : m_entities) {
            if(entity->enabled)
                entity->update(delta_time, events);
        }
    }

    void Window::add_entity(const std::shared_ptr<Entity>& entity) {
        entity->window = this;
        m_entities.push_back(entity);
    }

    std::shared_ptr<Entity> Window::get_entity_with_name(const char* name) {
        for(auto& entity : m_entities) {
            if(entity->name == name)
                return entity;
        }

        return nullptr;
    }
}