#include "Resources.h"
#include <filesystem>
#include <fstream>

using json = nlohmann::json;
namespace WillieNelson {

    Resources::Resources() {
        m_texture_handles = std::vector<TextureHandle>();
    }

    Resources* Resources::Current() {
        if(current == nullptr)
            current = new Resources();

        return current;
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