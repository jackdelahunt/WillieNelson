#include "SpriteComponent.h"
#include <iostream>
#include "imgui.h"

namespace WillieNelson {

    void SpriteComponent::start() {}

    void SpriteComponent::update(float delta_time, std::vector<sf::Event>& events) {
    }

    void SpriteComponent::set_texture(std::shared_ptr<sf::Texture>& texture) {
        m_sprite.setTexture(*texture);
    }

    void SpriteComponent::set_center(float relative_x, float relative_y) {
        m_sprite.setOrigin(m_sprite.getLocalBounds().width * relative_x, m_sprite.getLocalBounds().height * relative_y);
    }

    sf::Drawable* SpriteComponent::get_drawable() {
        return &m_sprite;
    }

    sf::Transformable *SpriteComponent::get_transform() {
        return &m_sprite;
    }

}