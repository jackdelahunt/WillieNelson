#pragma once
#include "common.h"

class Level2: public WillieNelson::Scene{
public:
    void attach(WillieNelson::Game &game) override {
        auto texture = WillieNelson::Resources::Current()->load_texture("../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

        auto game_object_1 = WillieNelson::Entity::New();
        auto sprite_1 = game_object_1->add_component<WillieNelson::SpriteComponent>();
        game_object_1->add_component<PlayerController>();
        sprite_1->set_texture(texture);

        game.add_entity(game_object_1);
    }
};


