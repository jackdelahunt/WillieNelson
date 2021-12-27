#pragma once
#include "common.h"

class Level2: public WillieNelson::Scene{
public:
    void attach(WillieNelson::Game &game) override {
        auto player_texture = WillieNelson::Resources::Current()->load_texture("../resources/bk_player_assets/player_hk_stand.png");

        auto tilemap_entity = WillieNelson::Entity::New();
        auto tilemap_component = tilemap_entity->add_component<WillieNelson::TilemapComponent>();
        tilemap_component->load_from_disk("level_2.json");
        tilemap_component->rebuild();
        tilemap_entity->transform.scale = sf::Vector2f(0.2f, 0.2f);

        auto game_object_1 = WillieNelson::Entity::New();
        auto sprite_1 = game_object_1->add_component<WillieNelson::SpriteComponent>();
        game_object_1->add_component<PlayerController>();
        sprite_1->set_texture(player_texture);

        game.add_entity(tilemap_entity);
        game.add_entity(game_object_1);
    }
};


