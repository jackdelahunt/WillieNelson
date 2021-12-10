from pysemble.builders import Project, Library
from pysemble.compilers import Clang
from pysemble.archivers import Ar
import os

compiler = Clang(version = "c++17", optimization = 2) # g++
archiver = Ar()

working_directory = os.path.dirname(os.path.realpath(__file__))
os.environ["LD_LIBRARY_PATH"] = working_directory + "/vendor/SFML-2.5.1/lib/:" + working_directory + "/libwilson/lib/"

project = Project("wilson", compiler)
project.add_executables([
    "game/main.cpp",
    "game/PlayerComponent.cpp",
])
project.add_link_path("libwilson/lib")
project.add_link_path("vendor/SFML-2.5.1/lib")
project.add_include_directory("libwilson/include")
project.add_include_directory("vendor/SFML-2.5.1/include/")
project.add_dynamic_libs([
    "stdc++",
    "sfml-graphics",
    "sfml-window",
    "sfml-system",
    "sfml-audio",
    "wilson"
])
project.build()
project.run()