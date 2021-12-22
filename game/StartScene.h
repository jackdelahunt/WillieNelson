#pragma once
#include "common.h"
#include "PlayerScript.h"

class StartScene: public WillieNelson::Scene {
public:
    void attach(WillieNelson::Window &window) override {
        auto texture = WillieNelson::Resources::Current()->load_texture("../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

        auto game_object_1 = WillieNelson::Entity::New();
        auto sprite_1 = game_object_1->add_component<WillieNelson::SpriteComponent>();
        game_object_1->add_component<PlayerScript>();
        sprite_1->set_texture(texture);
        auto boxCollider_1 = game_object_1->add_component<WillieNelson::BoxCollider>();

        auto game_object_2 = WillieNelson::Entity::New();
        auto sprite_2 = game_object_2->add_component<WillieNelson::SpriteComponent>();
        sprite_2->set_texture(texture);
        auto boxCollider_2 = game_object_2->add_component<WillieNelson::BoxCollider>();
        game_object_2->transform.position = sf::Vector2f(50.0f, 50.0f);
        window.add_entity(game_object);

        auto text_object = WillieNelson::Entity::New();
        auto text = text_object->add_component<WillieNelson::TextComponent>();
        text->set_font("Sansation_Regular");
        text->set_text("Cool Text Bro", sf::Color::Magenta, 100);

        window.add_entity(game_object_1);
        window.add_entity(game_object_2);
        window.add_entity(text_object);
    }
};