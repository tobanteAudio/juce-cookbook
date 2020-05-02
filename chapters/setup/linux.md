# Linux

## Dependencies

|    Program    |                  Description                   |            Comment            |
| :-----------: | :--------------------------------------------: | :---------------------------: |
|      x11      |             Unix windowing system.             |                               |
|   xinerama    |        Multi display extension to x11.         |                               |
|    LibXext    |            More extensions to x11.             |                               |
|    ALSA    |              ALSA sound library.               |                               |
|   freetype    |                 Font library.                  |                               |
|   glu1-mesa   |                                                |                               |
|  webkit2gtk   |             WebKit Browser Engine              | Optional `JUCE_WEB_BROWSER=0` |
| curl4-openssl |                  CURL library                  |  Optional `JUCE_USE_CURL=0`   |
|     CMake     |    Build file generator. Replaces Projucer     |           Optional            |
|     Ninja     | Build system similar to Makefiles, but faster. |           Optional            |
|     Clang     |                   Compiler.                    |           Optional            |

### Ubuntu

```sh
# Required
sudo apt install libx11-dev libxinerama-dev libxext-dev libfreetype6-dev libasound2-dev libglu1-mesa-dev
# Optional
sudo apt install libwebkit2gtk-4.0-dev libcurl4-openssl-dev
```

### ToDo

- Arch
- Fedora
- Raspberry PI

## Install

```sh
git clone https://github/juce-framework/JUCE.git
cd JUCE/extras/Projucer/Builds/LinuxMakefile
make config=Release -j8
```
