#pragma once

#include "Component.h"
#include "Window.h"

namespace WillieNelson {

    class AnimatedSpriteComponent : public Component, public WilsonWrapper {
    public:
        AnimatedSpriteComponent();

        void start() override {};

        void update(float delta_time, std::vector<sf::Event> &events) override;

        void append_texture(std::shared_ptr<sf::Texture> &texture);

        void next_frame();

        void set_interval(float time) { m_interval = time; }

        sf::Drawable *get_drawable() override;

        sf::Transformable *get_transform() override;

    private:
        int m_current_frame;
        float m_interval;
        float m_current_interval;
        std::vector<sf::Sprite> m_sprites;

    };
}
