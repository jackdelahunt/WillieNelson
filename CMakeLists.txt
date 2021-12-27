cmake_minimum_required(VERSION 3.20)
project(wilson)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "vendor/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(
                wilson
                game/main.cpp
                game/PlayerController.cpp game/PlayerController.h
                game/StartScene.h
                game/common.h
                game/BulletController.cpp game/BulletController.h
        game/Level2.h

                core/json.hpp
                core/Entity.cpp core/Entity.h
                core/Component.h
                core/SpriteComponent.cpp core/SpriteComponent.h
                core/Game.cpp core/Game.h
                core/Resources.cpp core/Resources.h
                core/Transform.h
                core/AnimatedSpriteComponent.cpp core/AnimatedSpriteComponent.h
                core/TilemapComponent.cpp core/TilemapComponent.h
                core/Scene.cpp core/Scene.h
                core/TextComponent.cpp core/TextComponent.h
                core/BoxCollider.cpp core/BoxCollider.h
                core/Physics.cpp core/Physics.h
                core/ButtonComponent.cpp core/ButtonComponent.h
        )

target_link_libraries(wilson sfml-graphics)