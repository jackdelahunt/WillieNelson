#include "Game.h"

#include <memory>
#include <exception>
#include <iostream>
#include "Physics.h"

#include "imgui.h"
#include "imgui-SFML.h"

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
        m_window = std::make_unique<sf::RenderWindow>(m_video_mode, "WillieNelson", sf::Style::Titlebar | sf::Style::Close);
        m_current_scene_index = 0;

        auto _ = ImGui::SFML::Init(*m_window);
    }

    void Game::start() {

        if(active_game != nullptr) {
            active_game->end();
        }

        active_game = this;

        if(m_current_scene_index < m_scenes.size()) {
            m_scenes.at(m_current_scene_index)->attach(*this);
        }

        init_scene();

        sf::Clock delta_clock;
        m_has_started = true;
        while (m_window->isOpen()) {
            m_has_changed_scene = false;
            auto events = poll_events();
            auto restart = delta_clock.restart();
            ImGui::SFML::Update(*m_window, restart);
            update(m_delta_time, events);
            m_fps_buffer.push(m_delta_time);
            draw_info();
            draw();
            m_delta_time = restart.asSeconds();
        }
        end();
    }

    void Game::end() {
        for(auto& entity : m_entities) {
            entity->Destroy();
        }
        m_entities.clear();
        ImGui::SFML::Shutdown();
    }

    std::vector<sf::Event> Game::poll_events() {
        auto events = std::vector<sf::Event>();
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(*m_window, event);
            if (event.type == sf::Event::Closed)
                end();

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
        ImGui::SFML::Render(*m_window);
        m_window->display();
    }

    void Game::update(float delta_time, std::vector<sf::Event>& events) {
        for(int i = 0; i < m_entities.size(); i++) {
            if(m_has_changed_scene) return;
            m_entities.at(i)->update(delta_time, events, &m_has_changed_scene);
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
        m_current_scene_index++;
        m_has_changed_scene = true;
        auto god_entities = clear_for_scene_change();
        m_has_started = false;
        auto s = m_scenes.size();

        std::cout << "Current Scene " << m_current_scene_index << std::endl;
        std::cout << "Total " << m_scenes.size() << std::endl;
        if(m_current_scene_index < m_scenes.size() && m_current_scene_index != 6) {
            m_scenes.at(m_current_scene_index)->attach(*this);
        }
        else if (m_current_scene_index == m_scenes.size()) {
            m_current_scene_index = 2;
            m_scenes.at(3)->attach(*this);
        }

        for(auto& g_ett : god_entities) {
            m_entities.push_back(g_ett);
        }

        init_scene();
    }

    void Game::scene_index(int index) {

        if(!(index < m_scenes.size() && index >= 0)) return;

        m_has_changed_scene = true;
        auto god_entities = clear_for_scene_change();
        m_current_scene_index = index;
        m_has_started = false;
        m_scenes.at(m_current_scene_index)->attach(*this);

        for(auto& g_ett : god_entities) {
            m_entities.push_back(g_ett);
        }
        init_scene();
    }

    void Game::draw_info() {
        ImGui::Begin("Info");
        ImGui::PlotLines("Frame Times", m_fps_buffer.buffer, m_fps_buffer.size, 0);
         auto s = std::to_string(1 / m_delta_time);
         ImGui::Text("%s", s.c_str());
        ImGui::End();
    }

    void Game::init_scene() {
        for(auto& e : m_entities) {
            e->start();
        }

        m_has_started = true;
    }

    std::vector<std::shared_ptr<Entity>> Game::clear_for_scene_change() {
        auto god_tiers = std::vector<std::shared_ptr<Entity>>();
        for(int i = m_entities.size() - 1; i >= 0; i--) {
            if(!m_entities.at(i)->god_mode) {
                m_entities.at(i)->Destroy();
            } else {
                god_tiers.push_back(m_entities.at(i));
            }
        }

        m_entities.clear();
        return god_tiers;
    }
}