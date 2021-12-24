#pragma once
#include "Component.h"
#include "Game.h"
#include "json.hpp"

using json = nlohmann::json;

namespace WillieNelson {
class TilemapComponent : public Component, public sf::Drawable, sf::Transformable, public WilsonWrapper{
    public:
        TilemapComponent();

        void start() override {};
        void update(float delta_time, std::vector<sf::Event>& events) override {};
        void destroy() override;
        bool load_from_disk(std::string name);
        json to_json();
        void from_json(json& j);

        sf::Drawable* get_drawable() override {
            return this;
        };

        sf::Transformable* get_transform() override {
            return this;
        };

        void reload();
        void rebuild();
        void set_tileset(const char* path);
        void set_tile(int x, int y, int value);
        int get_tile(size_t x, size_t y);
        sf::Vector2f get_world_position(int x, int y);
        sf::Vector2i get_tile_position(sf::Vector2f& world_position);

        void set_tile_dimensions(size_t width, size_t height) {
            m_tile_width = width;
            m_tile_height = height;
        }

        void set_dimensions(size_t width, size_t height) {
            m_width = width;
            m_height = height;
        }

    private:
        std::vector<int> m_tiles;
        size_t m_tile_width;
        size_t m_tile_height;
        size_t m_width;
        size_t m_height;
        sf::VertexArray m_vertices;
        std::string m_tileset_path;
        sf::Texture m_tileset;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= this->getTransform();

            // apply the tileset texture
            states.texture = &m_tileset;

            // draw the vertex array
            target.draw(m_vertices, states);
        }
    };
}


