#pragma once
#include "../core/Component.h"
#include "../core/Game.h"
#include "../core/json.hpp"

using json = nlohmann::json;

class ScoreComponent {
public:
    static ScoreComponent* Active();

    ScoreComponent();

    bool load_from_disk(std::string name);

    json to_json();

    void from_json(json &j);

    void save();

    std::vector<int> m_scores;

private:

};

static ScoreComponent* active_score = nullptr;

