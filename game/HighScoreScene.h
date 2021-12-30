#pragma once

#include <iostream>
#include "common.h"

class HighScoreScene: public WillieNelson::Scene{
public:
    void attach(WillieNelson::Game &game) override {

        /* -----------------
        * TEXT
        * ----------------- */
        {
            auto text_entity = WillieNelson::Entity::New();
            auto text = text_entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("Highest Scores", sf::Color::White, 65);

            text_entity->transform.position.x = (float) game.window().getSize().x / 2 - 225;
            text_entity->transform.position.y = 0;

            game.add_entity(text_entity);
        }

        {
            auto text_entity = WillieNelson::Entity::New();
            auto text = text_entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("1. 55555", sf::Color::White, 50);

            text_entity->transform.position.x = (float) game.window().getSize().x / 2 - 85;
            text_entity->transform.position.y = (float) game.window().getSize().y / 2 - 200;
            text_entity->name = "score1";

            game.add_entity(text_entity);
        }

        {
            auto text_entity = WillieNelson::Entity::New();
            auto text = text_entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("2. 44444", sf::Color::White, 50);

            text_entity->transform.position.x = (float) game.window().getSize().x / 2 - 85;
            text_entity->transform.position.y = (float) game.window().getSize().y / 2 - 100;
            text_entity->name = "score2";

            game.add_entity(text_entity);
        }

        {
            auto text_entity = WillieNelson::Entity::New();
            auto text = text_entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("3. 33333", sf::Color::White, 50);

            text_entity->transform.position.x = (float) game.window().getSize().x / 2 - 85;
            text_entity->transform.position.y = (float) game.window().getSize().y / 2;
            text_entity->name = "score2";

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
            button->set_button(256, 128, (int) game.window().getSize().x / 2 - 128,
                               (int) game.window().getSize().y / 2 + 128);
            button->send_call_back(
                    []() {
                        std::cout << "Button Call" << std::endl;
                        WillieNelson::Game::Active()->scene_index(0);
                    }
            );
            button_entity->transform.position.x = (float) game.window().getSize().x / 2 - 128;
            button_entity->transform.position.y = (float) game.window().getSize().y / 2 + 128;

            auto text_entity = WillieNelson::Entity::New();
            auto text = text_entity->add_component<WillieNelson::TextComponent>();
            text->set_font("Sansation_Regular");
            text->set_text("Return", sf::Color::White, 50);

            text_entity->transform.position.x = button_entity->transform.position.x + 50;
            text_entity->transform.position.y = button_entity->transform.position.y + 30;

            game.add_entity(button_entity);
            game.add_entity(text_entity);

        }

    }
};