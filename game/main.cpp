#include "../core/willie_nelson.h"
#include "StartScene.h"

int main() {
    auto window = WillieNelson::Window();
    window.add_scene<StartScene>();
    window.start();
}
