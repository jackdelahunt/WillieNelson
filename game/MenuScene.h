#pragma once

#include <iostream>
#include "common.h"

class MenuScene: public WillieNelson::Scene{
public:
    void attach(WillieNelson::Game &game) override {

        /* -----------------
         * BUTTON
         * ----------------- */
        {
            auto texture = WillieNelson::Resources::Current()->load_texture(
                    "../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

            auto entity = WillieNelson::Entity::New();
            auto button = entity->add_component<WillieNelson::ButtonComponent>();
            auto sprite = entity->add_component<WillieNelson::SpriteComponent>();
            auto text = entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("Play", sf::Color::White, 50);
            sprite->set_texture(texture);
            button->set_button(256, 128, game.window().getSize().x / 2, game.window().getSize().y / 2);
            button->send_call_back(
                    []() {
                        std::cout << "Button Call" << std::endl;
                        WillieNelson::Game::Active()->next_scene();
                    }
            );

            entity->transform.position.x = game.window().getSize().x / 2;
            entity->transform.position.y = game.window().getSize().y / 2;

            game.add_entity(entity);
        }
    }
};