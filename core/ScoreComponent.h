#pragma once
#include "Component.h"
#include "Game.h"
#include "json.hpp"

using json = nlohmann::json;

namespace WillieNelson {

    class ScoreComponent : public WillieNelson::Component {
    public:
        void start() override;

        void update(float delta_time, std::vector<sf::Event> &events) override;

        void destroy() override;

        bool load_from_disk(std::string name);

        json to_json();

        void from_json(json &j);


    private:
        std::vector<int> m_scores;
    };
}

