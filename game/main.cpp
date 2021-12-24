#include "StartScene.h"

int main() {
    auto game = WillieNelson::Game();
    game.add_scene<StartScene>();
    game.start();
}
