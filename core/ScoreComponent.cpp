#include "ScoreComponent.h"
#include "Resources.h"
#include <iostream>

namespace WillieNelson {

    void ScoreComponent::start() {}

    void ScoreComponent::update(float delta_time, std::vector<sf::Event> &events) {}

    void ScoreComponent::destroy() {
        auto json = to_json();
        WillieNelson::Resources::Current()->save("high_score.json", json);
    };

    bool ScoreComponent::load_from_disk(std::string name) {
        auto data = WillieNelson::Resources::Current()->try_load(name);
        if (data.has_value()) {
            from_json(data.value());
            return true;
        }

        return false;
    }

    json ScoreComponent::to_json() {
        json j;
        j["scores"] = m_scores;
        return j;
    }

    void ScoreComponent::from_json(json &j) {
        j.at("scores").get_to(this->m_scores);

        for(auto s : m_scores) {
            std::cout << s << std::endl;
        }
    }

}