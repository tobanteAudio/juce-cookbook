# JUCE Cookbook

**WARNING: WORK IN PROGRESS. SOME SECTION MIGHT NOT HAVE ANY CONTENT OR ONLY A LIST WITH KEYWORDS FOR ME AS A TODO LIST.**

A collection of examples & workflow tips related to the C++ libary JUCE.

## Content

- [Intro](#intro)
  - [Why did I write this](#why-did-i-write-this)
  - [About myself](#about-myself)
- [Disclaimer](#disclaimer)
- [Code license](#code-license)
- [Contribute](#contribute)
- [How to read](#how-to-read)
- [How to run examples](#how-to-run-examples)
- [Why JUCE](#why-juce)
  - [Features](#features)
    - [Audio](#audio)
    - [Mobil](#mobil)
- [Other libraries](#other-libraries)
  - [Qt](#qt)
  - [SFML](#sfml)
  - [imgui](#mgui)
- [Online resources](#online-resources)
- [C++](#c++)
- [Getting started](#getting-started)
  - [Project types](#project-types)
  - [Project setup](#project-setup)
  - [Project managment](#project-managment)
  - [Project documentation](#project-documentation)
  - [Platforms](#platforms)
    - [Linux](#Linux)
    - [Raspberry PI](#raspberry-pi)
  - [Project template](#project-template)
- [UI](#ui)
- [DSP](#dsp)
- [MVC](#mvc)
- [File IO](#file-io)
- [Network IO](#network-io)
- [OpenGL](#opengl)
- [Custom modules](#custom-modules)
- [Tracktion engine](#tracktion-engine)
- [Unit tests](#unit-tests)
- [Continuous integration](#continuous-integration)
  - [Travis CI](#travis-ci)
  - [Appveyor](#appveyor)
  - [Deploy](#deploy)
- [Publish](#publish)
- [My wishlist for JUCE](#my-wishlist-for-juce)
- [What next](#what-next)
- [Related resources](#related-resources)

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

All of my example code in this repository is published to the public domain under the [Creative Commons CC0 1.0](https://creativecommons.org/publicdomain/zero/1.0/deed.de) license.

## Contribute

If you find any bugs or design problems in my examples feel free to open up an issue on GitHub.

If you want to add examples or resources to this collection you can eather push a pull request directly or open up an issue first, if you have any questions.

## How to read

- Each chapter can be read individually

## How to run examples

All of the example projects included in this repository are normal `Projucer` projects, so running them is the same as any other project created with the `Projucer`

- Download JUCE
- Build the Projucer

### Windows & macOS

- Open example projects `.jucer` file & save to generate the build files
- Open the project in your IDE (Visual Studio / XCode)
- Build

### Linux

```sh
cd $PROJECT_ROOT
Projucer --resave $PROJECT_NAME.jucer
cd Builds/LinuxMakefile
make config=[Release, Debug] -j8
```

## Why JUCE

### Features

Long story short, JUCE is a library which solves many common problems a developer might face during the creation of any kind of application.
It hides away a lot of complexity, which normally is not very fun to work with. This includes cross platform window creation, file I/O, networking and so on.
JUCE also comes with a collection of user interface widgets, such as buttons, combo boxes, menus, tabbed views and many more. A complete list can be found
in the [JUCE documentation](https://docs.juce.com/master/index.html#tag_gui). `Components` as they are called in JUCE form the basis of all user interaction in a JUCE application.
The appearance is easily customizable. If the ones provided by JUCE don't fit your needs you can also create your own, just create subclass from the `Compoent` you want to customize and of you go.

#### Audio

- Wraps all common plugin types.
- Basic DSP & Analysis
- Vector instructions for x86 and ARM

#### Mobil

- Easily use C++ for both Android & iOS
- Use native features

## Other libraries

Of course JUCE is not the only library that helps you build desktop & mobile applications. There are a lot of open source frameworks & libraries that try to achieve similar goals.

The following list is definitely not complete, but should give you a good overview on what is available in the C++ ecosystem.

### QT

If you have been programming with C++ for a while, you probably heard of Qt. It's been around since the mid 90's and is currently being developed by The Qt Company.

The goal of Qt is to do it all. It runs on almost every platform including BSDs and embedded platforms. Because of this the whole framework is huge. While JUCE is around a couple of hundred megabytes, Qt is more in the range of a couple gigabytes.

Qt is also not really designed to help you write audio applications. There is no easy way to wrap a Qt application in an AudioUnit or VST plugin for example.

If your goal is to write a desktop application in the style of Gimp, FreeCAD or Blender and you need a lot of premade desktop widgets, Qt is probably the way to go.

Qt is free for open source projects, but a license for closed source application can become pretty expensive.

### SFML

- very simple
- intended for games

### IMGUI

- very simple
- intended for simple widgets
- works well with SFML
  - cpp_box

## Online resources

### Tutorials

- [JUCE tutorials](https://juce.com/learn/tutorials)

### Docs & Forum

The two most important resources when developing with JUCE are the official [JUCE documentation](https://juce.com/learn/documentation) & the [JUCE forum](https://forum.juce.com/).

The [API documentation](https://juce.com/learn/documentation) for JUCE is very good in my opinion. All of the classes & functions are clearly documented.

The same goes for the [forum](https://forum.juce.com/), every time I asked a question, it was answered on the same day, which compared to other communities is simply awesome.

### YouTube

If you like to learn using videos, you should be able to go from beginner to advanced using the resources found mainly on YouTube.

#### ADC Talks

The JUCE team has their own [YouTube channel](https://www.youtube.com/channel/UCaF6fKdDrSmPDmiZcl9KLnQ/videos), where yo can find all of the talks from the yearly `Audio Developer Confrence (ADC)`. The content goes from general audio development to JUCE basics to advanced, companies showing of their workflow using JUCE and much more. I will link to specific talks in later sections.

#### The Audio Programmer

The Audio Programmer is a YouTube channel which almost only does JUCE related development tutorials. He has videos for the basics on getting up & running with the library, introduction to `Components`, an introduction to audio plugin development and interviews with people working in the audio developer industry. Each video is `~20-60min` long.

If you are new to C++ and audio this is a create place to start.

If you are already pretty good in the language and have a basic understanding of audio in the digital world these videos will probably be a little to slow for you.

##### Discord

- Book
- Discord

## C++

- New to C++
- Modern standard
  - JUCE >= C++14
  - C++17 Features
  - C++20 Features
- Resources
  - CppWeekly
  - TheCherno
  - CppCon, etc.
  - Books
- Idioms
  - Inheritance
    - virtual / override
  - Lambdas
  - Constexpr
  - Smart Pointer (unique & shared)
  - Container (vectors & arrays)
  - noexcept where possible
  - const where possible
- Tools
  - IDE
    - Visual Studio
    - XCode
    - Makefile
    - Visual Studio Code
    - CodeBlocks
  - compiler
    - warnings are your friend
    - clang from source
    - cross platform different warnings
    - old versions in distros
  - clang-tidy
    - Visual Studio
    - from terminal/python script
  - clang-format
    - A must
    - Pick a standard
    - Visual Studio integration
    - python script
  - compiler-explorer
  - sanitizers
    - gcc & clang
  - Makefile/Scripts

## Getting Started

### Project Types

- AudioApp
- Plugin

### Project Setup

- Projucer
- AudioPluginHost
  - IDE Integration

### Project Managment

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

### Project template

## UI

- Basic Components
  - Top list
- Projucer live build
  - Tricks
- Animations
- LookAndFeel

## DSP

- DSP module
  - Gain example
  - Compressor example
- AudioProcessor
- Plugins
  - VST/AU
  - ValueTree/Undo

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

## Custom modules

## Tracktion Engine

## Unit tests

- JUCE unit tests
  - How to run them in a plugin build
- Catch2
- pluginval

## Continuous integration

Explaining the concepts of `continuous integration` and `continuous deployment` is far out of scope for this document, but TLDR: CI helps you find problems in your code faster. Every time you push to your version control server of choice (e.g. GitHub or GitLab) builds on various platforms start up. For example in my plugin project modEQ, I have builds for Windows, macOS & Linux. Since all of the platforms are using different compilers I get different warnings on each. Fixing all those little things as you go will save you a lot of time compared to developing exclusively on one platform and then trying to release it for a additional platform at the end.

There are many CI services online for free if your project is publicly available on GitHub or other platforms. I will focus on `travis-ci` and `appveyor` because those to combined will cover all desktop platforms JUCE supports (Windows, macOS & Linux).

### Travis CI

- macOS
- linux

### appveyor

- windows

### deploy

- docs
- app/plugin

## Publish

- GitHub releases
- zip
- installer/package

## My wishlist for JUCE

- FreeBSD support
- Build system
- More widgets

## What next

- Read the docs
- Read the source
- Read other app written in juce
  - modEQ
  - helm
  - temper

## Related resources

- Faust
  - YouTube
- std::audio
