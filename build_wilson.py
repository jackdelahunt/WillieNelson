from pysemble.builders import Project, Library
from pysemble.compilers import Clang
from pysemble.archivers import Ar
import os

compiler = Clang(version = "c++17", optimization = 1) # g++
archiver = Ar()

libwilson = Library("libwilson", compiler, archiver)
libwilson.add_sources([
    "core/AnimatedSpriteComponent.cpp",
    "core/SpriteComponent.cpp",
    "core/Entity.cpp",
    "core/Resources.cpp",
    "core/Scene.cpp",
    "core/TilemapComponent.cpp",
    "core/Window.cpp",
])
libwilson.add_include_directory("vendor/SFML-2.5.1/include/")
libwilson.add_headers([
    "core/AnimatedSpriteComponent.h",
    "core/SpriteComponent.h",
    "core/Entity.h",
    "core/Resources.h",
    "core/Scene.h",
    "core/TilemapComponent.h",
    "core/json.hpp",
    "core/Transform.h",
])
libwilson.package(dynamic=True)
