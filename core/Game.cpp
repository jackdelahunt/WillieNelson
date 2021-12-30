#include "Game.h"

#include <memory>
#include <exception>
#include <iostream>
#include "Physics.h"

namespace WillieNelson {
    Game* Game::Active() {
        if(active_game == nullptr) {
            // create a game first
            throw std::exception();
        }
        return active_game;
    }

    Game::Game() {
        m_video_mode = sf::VideoMode(1024, 665);
        m_window = std::make_unique<sf::RenderWindow>(m_video_mode, "WillieNelson");
        m_current_scene_index = 0;
    }

    void Game::start() {

        if(active_game != nullptr) {
            active_game->end();
        }

        active_game = this;

        if(m_current_scene_index < m_scenes.size()) {
            m_scenes.at(m_current_scene_index)->attach(*this);
        }

        for(auto& entity : m_entities) {
            entity->start();
        }

        sf::Clock delta_clock;
        float delta_time = 0.0f;
        m_has_started = true;
        while (m_window->isOpen()) {
            auto events = poll_events();
            update(delta_time, events);
            draw();
            delta_time = delta_clock.restart().asSeconds();
        }
        end();
    }

    void Game::end() {
        for(auto& entity : m_entities) {
            entity->Destroy();
        }
        m_entities.clear();
    }

    std::vector<sf::Event> Game::poll_events() {
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

    void Game::draw() {
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

    void Game::update(float delta_time, std::vector<sf::Event>& events) {
        for(int i = 0; i < m_entities.size(); i++) {
            m_entities.at(i)->update(delta_time, events);
        }
    }

    void Game::add_entity(const std::shared_ptr<Entity>& entity) {
        m_entities.push_back(entity);

        if(m_has_started) // runtime added entity
            entity->start();
    }

    void Game::remove_entity(Entity& entity) {
        int index = -1;
        for(int i = 0; i < m_entities.size(); i++) {
            if(m_entities.at(i).get() == &entity) {
                index = i;
                break;
            }
        }

        if(index == -1) return;

        // some crack cocaine c++ stl code
        auto iter = m_entities.begin() + index;
        if(iter < m_entities.end()) {
            m_entities.at(index)->Destroy();
            m_entities.erase(iter);
        }
    }

    sf::RenderWindow &Game::window() {
        return *m_window;
    }

    std::shared_ptr<Entity> Game::get_entity_with_name(const char* name) {
        for(auto& entity : m_entities) {
            if(entity->name == name)
                return entity;
        }

        return nullptr;
    }

    void Game::next_scene() {
        m_entities.clear();
        m_current_scene_index++;
        Physics::Current()->clear();
        m_has_started = false;
        auto s = m_scenes.size();
        if(m_current_scene_index < m_scenes.size()) {
            m_scenes.at(m_current_scene_index)->attach(*this);
        }

        this->start();
    }

    void Game::scene_index(int index) {

        if(index < m_scenes.size() && index >= 0) {
            m_entities.clear();
            m_current_scene_index = index;
            Physics::Current()->clear();
            m_has_started = false;
            m_scenes.at(m_current_scene_index)->attach(*this);
        }

        this->start();
    }
}