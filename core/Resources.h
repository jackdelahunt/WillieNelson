#pragma once

#include <vector>
#include <memory>
#include <optional>
#include "SFML/Graphics.hpp"
#include "json.hpp"

using json = nlohmann::json;

namespace WillieNelson {

    typedef struct {
        const char* name;
        std::shared_ptr<sf::Texture> texture;
    } TextureHandle;

    class Resources {
    public:
        Resources();
        static Resources* Current();

        std::shared_ptr<sf::Texture> load_texture(const char* path);
        void save(std::string name, json& json);
        std::optional<json> try_load(std::string name);

    private:
        std::vector<TextureHandle> m_texture_handles;
        void build_save_path();
    };

    static Resources* current = nullptr;
}