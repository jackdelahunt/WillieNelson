#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"

namespace WillieNelson {

     class Entity;

    class WilsonWrapper {
    public:
        virtual sf::Drawable* get_drawable() = 0;
        virtual sf::Transformable* get_transform() = 0;
    };

    class Window {
    public:
        Window();
        void start();
        std::vector<sf::Event> poll_events();
        void draw();
        void update(float delta_time, std::vector<sf::Event>& events);
        void end();
        void add_entity(const std::shared_ptr<Entity>& entity);
        std::shared_ptr<Entity> get_entity_with_name(const char* name);

        bool is_open() const { return m_window->isOpen(); }

    private:
        std::unique_ptr<sf::RenderWindow> m_window;
        std::vector<std::shared_ptr<Entity>> m_entities;
        sf::VideoMode m_video_mode;
    };
}
