# JUCE Cookbook

**WARNING: WORK IN PROGRESS. SOME SECTION MIGHT NOT HAVE ANY CONTENT OR ONLY A LIST WITH KEYWORDS FOR ME AS A TODO LIST.**

A collection of examples & workflow tips related to the C++ library JUCE.

[**Latest PDF (direct download)**](https://github.com/tobanteAudio/juce-cookbook/releases/latest/download/tobanteAudio-JUCE-Cookbook.pdf)

[**GitHub Repository**](https://github.com/tobanteAudio/juce-cookbook)

## Intro

### Why did I write this

I started using JUCE because I wanted to make my own audio plugins and after doing a little bit research JUCE seemed to be the way to go.

Over the last couple of years, I have collected all of the resources related to JUCE that I could find. The list of bookmarked pages & code snippets have grown to quite a collection, so I decided to publish them as a cheat sheet for myself and everybody else who uses or wants to use JUCE.

### About myself

I started with programming at the age of 10. C++ was my first and primary language for the first couple of years. I have since then used Python, JS & Golang. I currently studying computer science with a focus on embedded systems in Berlin.

## Disclaimer

I'm definitely not an expert in JUCE or C++. I do have a job as a C++ developer, but unfortunately not using JUCE. So if you find any problems in my examples, feel free to open an issue.

## Code license

JUCE is published under a dual license, it is free for open source & small projects. You can find their license for JUCE 5 [here](https://juce.com/juce-5-license).

All of my example code in this repository is published to the public domain under the [Creative Commons CC0 1.0](#license) license.

## Contribute

If you find any bugs or design problems in my examples feel free to open up an issue on GitHub.

If you want to add examples or resources to this collection you can either push a pull request directly or open up an issue first, if you have any questions. Please make sure that your topic is not already covered by one of the official JUCE tutorials. If you want to add to one of the official tutorials make sure you include a link to that page, so we can keep duplicate code as minimal as possible. Maintaining the same tutorial twice doesn't make much sense.

## C++

### New to C++

### Modern standard

- JUCE >= C++14
- C++17 Features
- C++20 Features

### Resources

#### TheCherno

- Focuses on Game & Graphics programming
- Good basic C++ concept videos

#### Conferences

- CppCon, etc.
- BoostCon
- ACCU
- ...

#### CppWeekly

#### Books

### Idioms

- Inheritance
  - virtual / override
- Lambdas
- Constexpr
- Smart Pointer (unique & shared)
- Container (vectors & arrays)
- noexcept where possible
- const where possible

### Tools

#### IDE

- Visual Studio
- XCode
- Makefile
- Visual Studio Code
- CLion

#### compiler

- warnings are your friend
- clang from source
- cross platform different warnings
- old versions in distros

#### clang-tidy

- Visual Studio
- from terminal/python script

#### clang-format

- A must
- Pick a standard
- Visual Studio integration
- python script

#### compiler-explorer

Online compiler. Great for testing small code snippets. Does not currently have `JUCE` installed unfortunatly.

#### coverage

- gcc + gcov & lcov
- clang + llvm-profdata & llvm-cov

#### sanitizers

- GCC & clang

  - ASAN
  - UBSAN
  - MSAN
  - TSAN

- MSVC
  - ASAN (32bit only)

#### Makefile/Scripts

- Makefile
- Shell scripts
- Projucer python bindings

## Getting Started

### Project Types

- ConsoleApp
- GuiApp
- AudioApp
- Plugin

### Project Setup

#### Projucer

- Quick Setup
- Perfect IDE integration
- Hard to link external code/libraries

#### CMake

- Interface targets
- Binary builder

### Project Run/Debugging

- AudioPluginHost
  - IDE Integration

### Project management

- git submodules
- living at head

### Project Documentation

- comments
- GitHub Pages
- Doxygen
- readthedocs

### Platforms

- Linux
  - Dependencies
  - Ubuntu
  - Arch
  - Fedora
- Raspberry PI

### Project Check-List

- clang-format
- clang-tidy
- Warnings
- Optimizations

## UI

- Basic Components
  - Button
  - Slider
  - Label
  - Combobox
- Projucer live build
  - Tricks
- Animations
- LookAndFeel
  - Colour IDs
  - Override functions
  - Look at JUCE implementations
- Custom components
  - Look&Feel methods

## DSP

- DSP module
  - Gain example
  - Compressor example
- AudioProcessor
- Plugins
  - VST/AU
- ValueTree
  - Parameters
  - Undo
  - Generic Editor
  - Attachments

## MVC

- Why
- Example
- Talk

## File IO

- Record/Playback
- Sampler

## Network IO

- OSC
  - Arduino

## OpenGL

- Text for 3 examples
- How to use GLEW
  - If not, how to get function pointers using `openglcontext.extensions`.

## 3rd Party Modules

Small and definitely not complete list of 3rd party JUCE modules.

| Name                                                                  | License        | Description                                                          | Comment                     |
| --------------------------------------------------------------------- | -------------- | -------------------------------------------------------------------- | --------------------------- |
| [ATK](https://github.com/mbrucher/AudioTK)                            | BSD 3          | An audio digital processing toolbox                                  | Haven't used yet.           |
| [FF Meters](https://github.com/ffAudio/ff_meters)                     | BSD 3          | Plug and play component to display LED meters for JUCE audio buffers | Using it in modEQ. Love it. |
| [Tracktion Engine](https://github.com/Tracktion/tracktion_engine)     | GPL/Commercial | A DAW framework                                                      | Haven't used yet.           |
| [Foleys Video Engine](https://github.com/ffAudio/foleys_video_engine) | GPL/Commercial | A video engine to load, play, assemble and write video               | Haven't used yet.           |

If you know of any other JUCE modules, fell free to open an issue so we cam add it to the list.

## Testing

### JUCE unit tests

- How to run them in a plugin build

### Catch2

- Link against CMake shared code target
- Register tests
- CTest

### pluginval

- Download or build from source
- Run with maximum strictness (10)
- Test AU & VST

### Valgrind

## Continuous integration

Explaining the concepts of `continuous integration` and `continuous deployment` is far out of scope for this document, but TLDR: CI helps you find problems in your code faster. Every time you push to your version control server of choice (e.g. GitHub or GitLab) builds on various platforms start up. For example in my plugin project modEQ, I have builds for Windows, macOS & Linux. Since all of the platforms are using different compilers I get different warnings on each. Fixing all those little things as you go will save you a lot of time compared to developing exclusively on one platform and then trying to release it for a additional platform at the end.

There are many CI services online for free if your project is publicly available on GitHub or other platforms. I will focus on `travis-ci` and `appveyor` because those to combined will cover all desktop platforms JUCE supports (Windows, macOS & Linux).

### Travis CI

- basics
- install deps
  - Linux fake xorg
- platform matrix
- push to gh-pages
- run pluginval
- full example

### Appveyor

- basic example
- matrix
- full example

### Deploy

- docs
- app/plugin

## Publish

- GitHub releases
- zip
- installer/package

## My wish list for JUCE

- FreeBSD support (Working on it, see [tobanteAudio/juce-freebsd-example](https://github.com/tobanteAudio/juce-freebsd-example))
- Build system (solved in JUCE6)
  - CMake
  - Multiple targets in one project
- Better Graphics API integration
  - Metal (coming in JUCE6)
  - Vulkan

## What next

- Read the docs
- Read the source
- Read other app written in JUCE
  - modEQ
  - helm
  - temper

## Related resources

- Faust
  - YouTube
- `std::audio`

## License
