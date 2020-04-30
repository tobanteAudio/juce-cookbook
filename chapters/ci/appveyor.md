# Appveyor

## Example Configuration

JUCE + CMake:

```yml
version: 0.1.0.{build}
clone_folder: C:/projects/project
branches:
  only:
    - master

image: Visual Studio 2019
platform: x64
configuration:
  - Release

install:
  - cd %APPVEYOR_BUILD_FOLDER%
  - git submodule update --init --recursive

build:
  parallel: true

build_script:
  - cd C:/projects/project
  - mkdir build
  - cd build
  - cmake -G "Visual Studio 16 2019" ..
  - cmake --build . --config Release
```
