#pragma once

#include <iostream>
#include "common.h"
#include "PlayerController.h"

class StartScene: public WillieNelson::Scene {
public:
    void attach(WillieNelson::Game &game) override {


        /* -----------------
         * TILEMAP
         * ----------------- */
        {
            auto entity = WillieNelson::Entity::New();
            auto tilemap = entity->add_component<WillieNelson::TilemapComponent>();
            tilemap->load_from_disk("level_1.json");
            tilemap->rebuild();
            entity->transform.scale = sf::Vector2f(0.2f, 0.2f);
            game.add_entity(entity);
        }

        /* -----------------
         * PLAYER
         * ----------------- */
        {
            auto texture = WillieNelson::Resources::Current()->load_texture("../resources/bk_player_assets/player_hk_stand.png");
            auto entity = WillieNelson::Entity::New();
            entity->name = "player";
            auto sprite = entity->add_component<WillieNelson::SpriteComponent>();
            entity->add_component<PlayerController>();
            sprite->set_texture(texture);
            game.add_entity(entity);
        }

        /* -----------------
         * ZOMBIE(s)
         * ----------------- */

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
            text->set_text("Level 2", sf::Color::White, 50);
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
        }
    }
};