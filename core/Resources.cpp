#include "Resources.h"
#include <filesystem>
#include <fstream>

using json = nlohmann::json;
namespace WillieNelson {

    Resources::Resources() {
        m_texture_handles = std::vector<TextureHandle>();
    }

    Resources* Resources::Current() {
        if(current_resources == nullptr)
            current_resources = new Resources();

        return current_resources;
    }

    std::shared_ptr<sf::Texture> Resources::load_texture(const char* path) {

        for(auto& handle : m_texture_handles) {
            if(handle.name == path) return handle.texture;
        }

        auto texture = std::make_shared<sf::Texture>();
        texture->loadFromFile(path);
        m_texture_handles.push_back((TextureHandle) {.name = path, .texture = texture});
        return texture;
    }

    std::shared_ptr<sf::SoundBuffer> Resources::load_sound(const char *path) {
        for(auto& handle : m_sound_handles) {
            if(handle.name == path) return handle.sound_buffer;
        }

        auto buffer = std::make_shared<sf::SoundBuffer>();
        buffer->loadFromFile(path);
        m_sound_handles.push_back((SoundHandle) {.name = path, .sound_buffer= buffer});
        return buffer;
    }

    void Resources::build_save_path() {
        std::filesystem::create_directory("data");
    }

    void Resources::save(std::string name, json& json) {
        build_save_path();
        std::ofstream out;
        out.open("data/" + name);
        out << json;
        out.close();
    }

    std::optional<json> Resources::try_load(std::string name) {
        build_save_path();
        if(std::filesystem::exists("data/" + name)) {
            json json;
            std::ifstream in;
            in.open("data/" + name);
            in >> json;
            in.close();
            return json;
        }
        return std::optional<json> {};
    }
}