#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Scene.h"
#include "MovableBuffer.h"

namespace WillieNelson {

    class Entity;
    class Scene;

    class WilsonWrapper {
    public:
        virtual sf::Drawable* get_drawable() = 0;
        virtual sf::Transformable* get_transform() = 0;
    };

    class Game {
    public:
        static Game* Active();

        Game();
        void start();
        std::vector<sf::Event> poll_events();
        void draw();
        void update(float delta_time, std::vector<sf::Event>& events);
        void end();
        void add_entity(const std::shared_ptr<Entity>& entity);
        void remove_entity(Entity& entity);
        sf::RenderWindow& window();
        std::shared_ptr<Entity> get_entity_with_name(const char* name);
        bool is_open() const { return m_window->isOpen(); }
        void next_scene();

        template<typename T>
        void add_scene() {
            auto generic_ptr = std::make_shared<T>();
            auto scene = std::static_pointer_cast<Scene>(generic_ptr);
            if(scene != nullptr) {
                m_scenes.push_back(scene);
            }
        }

    private:
        std::unique_ptr<sf::RenderWindow> m_window;
        std::vector<std::shared_ptr<Entity>> m_entities;
        std::vector<std::shared_ptr<Scene>> m_scenes;
        sf::VideoMode m_video_mode;
        size_t m_current_scene_index;
        bool m_has_started = false;
        float m_delta_time = 0.0f;
        MovableBuffer m_fps_buffer = MovableBuffer(300);

        void draw_info();
    };

    static Game* active_game = nullptr;
}
