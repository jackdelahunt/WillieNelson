#pragma once

#include <iostream>
#include "common.h"

class MenuScene: public WillieNelson::Scene{
public:
    void attach(WillieNelson::Game &game) override {
        /* -----------------
         * BUTTON START
         * ----------------- */
        {
            auto texture = WillieNelson::Resources::Current()->load_texture(
                    "../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

            auto button_entity = WillieNelson::Entity::New();
            auto button = button_entity->add_component<WillieNelson::ButtonComponent>();
            auto sprite = button_entity->add_component<WillieNelson::SpriteComponent>();
            sprite->set_texture(texture);
            button->set_button(256, 128, (int)game.window().getSize().x / 2 - 128, (int)game.window().getSize().y / 2 - 256);
            button->send_call_back(
                    []() {
                        std::cout << "Button Call" << std::endl;
                        WillieNelson::Game::Active()->scene_index(2);
                    }
            );
            button_entity->transform.position.x = (float) game.window().getSize().x / 2 - 128;
            button_entity->transform.position.y = (float) game.window().getSize().y / 2 - 256;

            auto text_entity = WillieNelson::Entity::New();
            auto text = text_entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("Play", sf::Color::White, 50);

            text_entity->transform.position.x = button_entity->transform.position.x + 85;
            text_entity->transform.position.y = button_entity->transform.position.y + 30;

            game.add_entity(button_entity);
            game.add_entity(text_entity);

        }

        /* -----------------
        * BUTTON HIGH SCORE
        * ----------------- */
        {
                auto texture = WillieNelson::Resources::Current()->load_texture(
        "../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

        auto button_entity = WillieNelson::Entity::New();https://github.com/Iodinex64?tab=overview&from=2021-12-01&to=2021-12-30
        auto button = button_entity->add_component<WillieNelson::ButtonComponent>();
        auto sprite = button_entity->add_component<WillieNelson::SpriteComponent>();
        sprite->set_texture(texture);
        button->set_button(256, 128, (int)game.window().getSize().x / 2 - 128, (int)game.window().getSize().y / 2 - 64);
        button->send_call_back(
        []() {
            std::cout << "Button Call" << std::endl;
            WillieNelson::Game::Active()->scene_index(1);
        }
        );
        button_entity->transform.position.x = (float) game.window().getSize().x / 2 - 128;
        button_entity->transform.position.y = (float) game.window().getSize().y / 2 - 64;

        auto text_entity = WillieNelson::Entity::New();
        auto text = text_entity->add_component<WillieNelson::TextComponent>();
        text->set_font("Sansation_Regular");
        text->set_text("High Score", sf::Color::White, 50);

        text_entity->transform.position.x = button_entity->transform.position.x;
        text_entity->transform.position.y = button_entity->transform.position.y + 30;

        game.add_entity(button_entity);
        game.add_entity(text_entity);

        }

        /* -----------------
        * BUTTON QUIT
        * ----------------- */
        {
            auto texture = WillieNelson::Resources::Current()->load_texture(
                    "../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

            auto button_entity = WillieNelson::Entity::New();
            auto button = button_entity->add_component<WillieNelson::ButtonComponent>();
            auto sprite = button_entity->add_component<WillieNelson::SpriteComponent>();
            sprite->set_texture(texture);
            button->set_button(256, 128, (int)game.window().getSize().x / 2 - 128, (int)game.window().getSize().y / 2 + 128);
            button->send_call_back(
                    []() {
                        std::exit(1);
                    }
            );
            button_entity->transform.position.x = (float) game.window().getSize().x / 2 - 128;
            button_entity->transform.position.y = (float) game.window().getSize().y / 2 + 128;

            auto text_entity = WillieNelson::Entity::New();
            auto text = text_entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("Quit", sf::Color::White, 50);

            text_entity->transform.position.x = button_entity->transform.position.x + 85;
            text_entity->transform.position.y = button_entity->transform.position.y + 30;

            game.add_entity(button_entity);
            game.add_entity(text_entity);

        }
    }
};