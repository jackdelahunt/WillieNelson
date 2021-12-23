#include <iostream>
#include "TextComponent.h"

namespace WillieNelson {
    void TextComponent::start() {}

    void TextComponent::update(float delta_time, std::vector<sf::Event>& events) {}

    void TextComponent::set_font() {
        if (!m_font.loadFromFile("../resources/fonts/Sansation_Regular.ttf"))
        {
            std::cout << "Error loading file" << std::endl;
        }

    }

    void TextComponent::set_text() {
        m_text.setFont( m_font );
        m_text.setString("Yee Haw");
    }

    sf::Drawable* TextComponent::get_drawable() {
        return &m_text;
    }

    sf::Transformable *TextComponent::get_transform() {
        return &m_text;
    }
}
