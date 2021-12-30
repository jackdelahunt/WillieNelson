#include "StartScene.h"
#include "Level2.h"
#include "MenuScene.h"
#include "HighScoreScene.h"
#include "Level3.h"

int main() {
    auto game = WillieNelson::Game();
    game.add_scene<MenuScene>(); // 0
    game.add_scene<HighScoreScene>();// 1
    game.add_scene<StartScene>();// 2
    game.add_scene<Level2>();// 3
    game.add_scene<Level3>(); // 4
    game.start();
}
