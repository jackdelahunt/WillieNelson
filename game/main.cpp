#include "StartScene.h"
#include "Level2.h"
#include "MenuScene.h"
#include "HighScoreScene.h"

int main() {
    auto game = WillieNelson::Game();
    game.add_scene<MenuScene>();
    game.add_scene<HighScoreScene>();
    game.add_scene<StartScene>();
    game.add_scene<Level2>();
    game.start();
}
