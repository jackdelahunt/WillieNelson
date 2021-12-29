#pragma once
#include "Component.h"
#include "SFML/Audio.hpp"

namespace WillieNelson {
    class SoundComponent : public WillieNelson::Component {
    public:
        void start() override;
        void update(float delta_time, std::vector<sf::Event> &events) override;
        void destroy() {}
        void set_sound(std::shared_ptr<sf::SoundBuffer> &buffer);
        void play();
        bool is_playing();

    private:
        sf::Sound m_sound;
        std::shared_ptr<sf::SoundBuffer> m_sound_buffer;
    };
}