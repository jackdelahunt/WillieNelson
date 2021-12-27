#pragma once
#include "common.h"
#include "PlayerController.h"

class StartScene: public WillieNelson::Scene {
public:
    void attach(WillieNelson::Game &game) override {
        auto texture = WillieNelson::Resources::Current()->load_texture("../resources/battle-location-top-down-game-tileset-pack/PNG/Blocks/Block_A_01.png");

        auto game_object_1 = WillieNelson::Entity::New();
        auto sprite_1 = game_object_1->add_component<WillieNelson::SpriteComponent>();
        game_object_1->add_component<PlayerController>();
        sprite_1->set_texture(texture);

        game.add_entity(game_object_1);

        auto text_object = WillieNelson::Entity::New();
        auto text = text_object->add_component<WillieNelson::TextComponent>();
        text->set_font("Sansation_Regular");
        text->set_text("Cool Text Bro", sf::Color::Magenta, 100);

        //window.add_entity(text_object);

        auto button_object = WillieNelson::Entity::New();
        auto button = text_object->add_component<WillieNelson::ButtonComponent>();
        button->set_button(25,25,0,0);

        game.add_entity(button_object);
    }
};