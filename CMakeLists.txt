cmake_minimum_required(VERSION 3.20)
project(wilson)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "vendor/SFML-2.5.1/lib/cmake/SFML")
set(IMGUI_DIR "vendor/imgui")
set(IMGUI_SFML_DIR "vendor/imgui-sfml")

include_directories(${IMGUI_DIR} ${IMGUI_SFML_DIR} ${OPENGL_INCLUDE_DIRS})

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(
                wilson
                game/main.cpp
                game/PlayerController.cpp game/PlayerController.h
                game/common.h
                game/BulletController.cpp game/BulletController.h
                game/ZombieController.cpp game/ZombieController.h
                game/Spawner.cpp game/Spawner.h
                game/Weapon.h

                game/MenuScene.h
                game/HighScoreScene.h
                game/StartScene.h
                game/Level1.h
                game/Level2.h
                game/Level3.h

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
                core/SoundComponent.cpp core/SoundComponent.h
                core/imconfig-SFML.h
                core/imgui-SFML_export.h
                core/MovableBuffer.h
                core/ScoreComponent.cpp core/ScoreComponent.h

        vendor/imgui/imgui.cpp
                vendor/imgui/imgui_widgets.cpp
                vendor/imgui/imgui_draw.cpp
                vendor/imgui/imgui_tables.cpp
                vendor/imgui-sfml/imgui-SFML.cpp
        )

target_link_libraries(wilson ${OPENGL_LIBRARIES} sfml-graphics sfml-audio)