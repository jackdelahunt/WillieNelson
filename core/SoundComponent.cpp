#include "SoundComponent.h"

void SoundComponent::start() {
    m_sound = sf::Sound();
}

void SoundComponent::update(float delta_time, std::vector<sf::Event> &events) {

}

void SoundComponent::set_sound(std::shared_ptr<sf::SoundBuffer> &buffer) {
    m_sound_buffer = buffer;
    m_sound.setBuffer(*m_sound_buffer);
}

void SoundComponent::play() {
    m_sound.play();
}
