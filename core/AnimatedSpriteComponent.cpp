#include "AnimatedSpriteComponent.h"

AnimatedSpriteComponent::AnimatedSpriteComponent() {
    m_current_frame = 0;
    m_sprites = std::vector<sf::Sprite>();
}

void AnimatedSpriteComponent::update(float delta_time, std::vector<sf::Event>& events) {
    m_current_interval -= delta_time;

    if(m_current_interval <= 0.0f) {
        m_current_interval = m_interval;
        next_frame();
    }
}

void AnimatedSpriteComponent::append_texture(std::shared_ptr<sf::Texture>& texture) {
    auto sprite = sf::Sprite();
    sprite.setTexture(*texture);
    m_sprites.push_back(sprite);
}

void AnimatedSpriteComponent::next_frame() {
    m_current_frame++;
    if(m_current_frame >= m_sprites.size())
        m_current_frame = 0;
}

sf::Drawable* AnimatedSpriteComponent::get_drawable() {
    return &m_sprites.at(m_current_frame);
}

sf::Transformable* AnimatedSpriteComponent::get_transform() {
    return &m_sprites.at(m_current_frame);
}
