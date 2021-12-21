#include "../core/willie_nelson.h"
#include "StartScene.h"

int main() {
    auto window = WillieNelson::Window();
    auto start_scene = StartScene();
    start_scene.attach(window);
    window.start();
}
