#pragma once
#include "common.h"

class Level3: public WillieNelson::Scene{
public:
    void attach(WillieNelson::Game &game) override {


        /* -----------------
         * TILEMAP
         * ----------------- */
        {
            auto entity = WillieNelson::Entity::New();
            auto tilemap = entity->add_component<WillieNelson::TilemapComponent>();
            tilemap->load_from_disk("level_3.json");
            tilemap->rebuild();
            entity->transform.scale = sf::Vector2f(0.2f, 0.2f);
            game.add_entity(entity);
        }

    }
};