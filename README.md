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

Over the last couple of years, I have collected all of the resources related to JUCE that I could find. The list of bookmarked pages & code snippets have grown to quite a collection, so I decided to publish them as a cheatsheet for myself and everybody else who uses or wants to use JUCE.

### About myself

I started with programming at the age of 10. C++ was my first and primary language for the first couple of years. I have since then used Python, JS & Golang. I currently studying computer science with a focus on embedded systems in Berlin.

## Disclaimer

I'm definitely not an expert in JUCE or C++. I do have a job as a C++ developer, but unfortunatly not using JUCE. So if you find any problems in my examples, feel free to open an issue.

## Code license

JUCE is published under a dual license, it is free for open source & small projects. You can find their license for JUCE 5 [here](https://juce.com/juce-5-license).

All of my example code in this repository is published to the public domain under the [Creative Commons CC0 1.0](https://creativecommons.org/publicdomain/zero/1.0/deed.de) license.

## Contribute

If you find any bugs or design problems in my examples feel free to open up an issue on Github.

If you want to add examples or resources to this collection you can eather push a pull request directly or open up an issue first, if you have any questions.

## How to read

- Each chapter can be read individually

## How to run examples

- Windows
- Mac
- Linux

## Why JUCE

### Features

- Cross platform
- Collection of GUI widgets
- Easially customizable
- Solves common application problems (File IO, Network & Undo)

#### Audio

- Wraps all common plugin types.
- Basic DSP & Analysis
- Vector instructions for x86 and ARM

#### Mobil

- Easilly use C++ for both Android & iOS
- Use native features

## Other libraries

### Qt

- Not really intended for realtime audio
- To big
- expensive

### SFML

- very simple
- intended for games

### imgui

- very simple
- intented for simple widgets
- works well with SFML
  - cpp_box

## Online resources

### Tutorials

- [JUCE tutorials](https://juce.com/learn/tutorials)

### Docs & Forum

The two most importanted resources when developing with JUCE are the official [JUCE documentation](https://juce.com/learn/documentation) & the [JUCE forum](https://forum.juce.com/)

### Youtube

#### The Audio Programmer

#### ADC Talks

### Books & Chats

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
- Idiums
  - Inheritence
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
- Github Pages
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

### Travis CI

- macOS
- linux

### appveyor

- windows

### deploy

- docs
- app/plugin

## Publish

- Github releases
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
  - Youtube
- std::audio
