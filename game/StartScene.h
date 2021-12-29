#pragma once

#include <iostream>
#include "common.h"
#include "PlayerController.h"
#include "ZombieController.h"
#include "Spawner.h"

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
        auto texture = WillieNelson::Resources::Current()->load_texture("../resources/bk_player_assets/player_hk_stand.png");
        {
            auto entity = WillieNelson::Entity::New();
            entity->name = "player";
            auto sprite = entity->add_component<WillieNelson::SpriteComponent>();
            auto box_collider = entity->add_component<WillieNelson::BoxCollider>();
            auto sound = WillieNelson::Resources::Current()->load_sound("./resources/sounds/laserShoot.wav");
            entity->add_component<WillieNelson::SoundComponent>()->set_sound(sound);

            box_collider->set_dimensions(25, 25);
            entity->add_component<PlayerController>();
            sprite->set_texture(texture);
            game.add_entity(entity);
        }

        /* -----------------
         * SPAWNER(s)
         * ----------------- */
        {
            auto entity = WillieNelson::Entity::New();
            entity->add_component<Spawner>();
            entity->transform.position = sf::Vector2f(500.f, 500.f);
            game.add_entity(entity);
        }

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

            // game.add_entity(entity);
        }

        /* -------------
         * UI
         * ------------- */


        // === Score ===
        {
            auto entity = WillieNelson::Entity::New();
            auto text_score = entity->add_component<WillieNelson::TextComponent>();
            entity->name = "ui_score_entity";
            text_score->set_font("Sansation_Regular");
            text_score->set_text("Score : 00000", sf::Color::White, 30);

            entity->transform.position = sf::Vector2f(10.f,10.f);


            game.add_entity(entity);

        }

        // === Ammo ===
        {
            auto UIentity = WillieNelson::Entity::New();
            auto text_score = UIentity->add_component<WillieNelson::TextComponent>();
            UIentity->name = "ui_ammo_entity";
            text_score->set_font("Sansation_Regular");
            text_score->set_text("Ammo : 50", sf::Color::White, 30);

            UIentity->transform.position = sf::Vector2f(game.window().getSize().x - 190.f,10.f);


            game.add_entity(UIentity);
        }

        // === Health ===
        {
            auto UIentity = WillieNelson::Entity::New();
            auto text_score = UIentity->add_component<WillieNelson::TextComponent>();
            UIentity->name = "ui_health_entity";
            text_score->set_font("Sansation_Regular");
            text_score->set_text("100%", sf::Color::Red, 30);

            UIentity->transform.position = sf::Vector2f(game.window().getSize().x / 2 - 25.f,10.f);


            game.add_entity(UIentity);
        }

        // === Round Number ===
        {
            auto UIentity = WillieNelson::Entity::New();
            auto text_score = UIentity->add_component<WillieNelson::TextComponent>();
            UIentity->name = "ui_round_entity";
            text_score->set_font("Sansation_Regular");
            text_score->set_text("234", sf::Color::White, 40);

            UIentity->transform.position = sf::Vector2f(10.f, game.window().getSize().y - 50.f);


            game.add_entity(UIentity);
        }
    }
};