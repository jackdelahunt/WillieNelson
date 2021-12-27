#pragma once

#include <iostream>
#include "common.h"
#include "PlayerController.h"

class StartScene: public WillieNelson::Scene {
public:
    void attach(WillieNelson::Game &game) override {
        auto player_texture = WillieNelson::Resources::Current()->load_texture("../resources/bk_player_assets/player_hk_stand.png");


        auto tilemap_entity = WillieNelson::Entity::New();
        auto tilemap_component = tilemap_entity->add_component<WillieNelson::TilemapComponent>();
        tilemap_component->load_from_disk("level_1.json");
        tilemap_component->rebuild();
        tilemap_entity->transform.scale = sf::Vector2f(0.2f, 0.2f);

        auto player_entity = WillieNelson::Entity::New();
        auto sprite_component = player_entity->add_component<WillieNelson::SpriteComponent>();
        player_entity->add_component<PlayerController>();
        sprite_component->set_texture(player_texture);

        //window.add_entity(text_object);

        //Button

        auto texture2 = WillieNelson::Resources::Current()->load_texture("../resources/battle-location-top-down-game-tileset-pack/PNG/Tiles/Ground_Tile_01_B.png");

        auto button_object = WillieNelson::Entity::New();
        auto button = button_object->add_component<WillieNelson::ButtonComponent>();
        auto sprite = button_object->add_component<WillieNelson::SpriteComponent>();
        sprite->set_texture(texture2);
        button->set_button(256,256,0,0);
        button->send_call_back(
                []() {
                    std::cout << "Button Call" << std::endl;
                }
                );

        game.add_entity(tilemap_entity);
        game.add_entity(button_object);
        game.add_entity(player_entity);
    }
};