#include "StartScene.h"
#include "Level2.h"

int main() {
    auto game = WillieNelson::Game();
    game.add_scene<StartScene>();
    game.add_scene<Level2>();
    game.start();
}
