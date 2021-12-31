# Willie Nelson
## About
Willie Nelson is a game engine built by Jack Delahunt and Adrian Hebel. This repository also includes a game in the `game` directory that uses the engine located in `core`. This project is built with Cmake in mind meaning any other build system you may use might not work smoothly.

### Feature List
- ECS
- Sounds
- Colliders
- Animated sprites
- Changable scenes
- UI Components
    - Buttons
    - Text




## Build
First clone the entire project and it's submodules into a known directory.
```bash
git clone --recursive git@github.com:jackdelahunt/WillieNelson.git
```
```bash
cd WillieNelson
```
### Cmake
Cmake builds the entire project, meanng the engine and game are built into the final executable. To do this follow the bellow steps.
```bash
make run
```

## Troubleshooting
### Building
Some things could go wrong when running the `run` make command, the prerequisites for running this are:
- Cmake (>= 3.20)
- Make

If you do not have these installed make sure to get them for your system.

And if you are a windows user run the MakeFile in powershell to have access to unix like commands.
### ImGUI-SFML
If you are having problems finding ImGUI-SFML it may because you clone the repository incorrectly. Make sure to clone all submodules, with the `--recursive` flag in git.
### OpenAL
If you are having linking errors in realtion to sfml-audio, make sure you have the latest OpenAL packages installed on your machine.
### OpenGL
If you are having linking errors in realtion to sfml-grpahics or ImGUI, make sure you have the latest OpenGL packages installed on your machine.
