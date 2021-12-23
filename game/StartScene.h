#pragma once
#include "../core/Window.h"
#include "../core/Scene.h"
#include "../core/Resources.h"

class StartScene: public WillieNelson::Scene {
public:
    void attach(WillieNelson::Window &window) override {
        auto texture = WillieNelson::Resources::Current()->load_texture("../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

        auto game_object = WillieNelson::Entity::New();
        auto sprite = game_object->add_component<WillieNelson::SpriteComponent>();
        sprite->set_texture(texture);

        window.add_entity(game_object);

        auto text_object = WillieNelson::Entity::New();
        auto text = text_object->add_component<WillieNelson::TextComponent>();
        text->set_font();
        text->set_text();

        window.add_entity(text_object);
    }
};