#include <iostream>
#include "TextComponent.h"

namespace WillieNelson {
    void TextComponent::start() {}

    void TextComponent::update(float delta_time, std::vector<sf::Event>& events) {}

    void TextComponent::set_font(const std::string& fontName) {
        if (!m_font.loadFromFile("../resources/fonts/" + fontName + ".ttf"))
        {
            std::cout << "Error loading file" << std::endl;
        }
    }

    void TextComponent::set_text(const std::string& textName, sf::Color color, int size) {
        m_text.setFont( m_font );
        m_text.setString(textName);
        m_text.setFillColor(color);
        m_text.setCharacterSize(size);
    }

    void TextComponent::set_text(const std::string& textName) {
        //m_text.setFont( m_font );
        m_text.setString(textName);
    }

    sf::Drawable* TextComponent::get_drawable() {
        return &m_text;
    }

    sf::Transformable *TextComponent::get_transform() {
        return &m_text;
    }


}
