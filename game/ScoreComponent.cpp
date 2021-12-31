#include "ScoreComponent.h"
#include "../core/Resources.h"
#include <iostream>


ScoreComponent* ScoreComponent::Active() {
    if(active_score == nullptr) {
        active_score = new ScoreComponent();
    }
    return active_score;
}

ScoreComponent::ScoreComponent() {

}

void ScoreComponent::save() {
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

