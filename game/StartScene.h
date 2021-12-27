#pragma once

#include <iostream>
#include "common.h"
#include "PlayerController.h"

class StartScene: public WillieNelson::Scene {
public:
    void attach(WillieNelson::Game &game) override {
        auto texture = WillieNelson::Resources::Current()->load_texture("../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");


        auto tilemap_entity = WillieNelson::Entity::New();
        auto tilemap_component = tilemap_entity->add_component<WillieNelson::TilemapComponent>();
        tilemap_component->load_from_disk("level_1.json");
        tilemap_component->rebuild();
        tilemap_entity->transform.scale = sf::Vector2f(0.2f, 0.2f);

        auto player_entity = WillieNelson::Entity::New();
        auto sprite_component = player_entity->add_component<WillieNelson::SpriteComponent>();
        player_entity->add_component<PlayerController>();
        sprite_component->set_texture(texture);

        game.add_entity(tilemap_entity);
        game.add_entity(player_entity);
        //window.add_entity(text_object);

        //Button

        auto texture2 = WillieNelson::Resources::Current()->load_texture("../resources/battle-location-top-down-game-tileset-pack/PNG/Tiles/Ground_Tile_01_B.png");
        auto game_object_2 = WillieNelson::Entity::New();
        auto sprite_2 = game_object_2->add_component<WillieNelson::SpriteComponent>();
        sprite_2->set_texture(texture2);

        game.add_entity(game_object_2);


        auto button_object = WillieNelson::Entity::New();
        auto button = button_object->add_component<WillieNelson::ButtonComponent>();
        button->set_button(256,256,0,0);
        button->send_call_back(
                []() {
                    std::cout << "Button Call" << std::endl;
                }
                );

        game.add_entity(button_object);
    }
};