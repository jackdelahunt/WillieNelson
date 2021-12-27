#pragma once
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
    }
};