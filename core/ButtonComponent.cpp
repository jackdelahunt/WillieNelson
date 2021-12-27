
#include "ButtonComponent.h"
#include "SpriteComponent.h"

namespace WillieNelson {

    void ButtonComponent::start() {}

    void ButtonComponent::update(float delta_time, std::vector<sf::Event>& events) {}

    void ButtonComponent::set_button(float width, float height, float xPos, float yPos) {
        m_button_pos = sf::Vector2f(xPos, yPos);
        m_button_size = sf::Vector2f(width,height);
        m_shape = sf::RectangleShape(m_button_size);
    }


    sf::Drawable* ButtonComponent::get_drawable() {
        return &m_shape;
    }

    sf::Transformable *ButtonComponent::get_transform() {
        return &m_shape;
    }
}