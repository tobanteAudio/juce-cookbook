# JUCE Cookbook

**WARNING: WORK IN PROGRESS. SOME SECTION MIGHT NOT HAVE ANY CONTENT OR ONLY A LIST WITH KEYWORDS FOR ME AS A TODO LIST.**

A collection of examples & workflow tips related to the C++ library JUCE.

[**Latest PDF (direct download)**](https://github.com/tobanteAudio/juce-cookbook/releases/latest/download/tobanteAudio-JUCE-Cookbook.pdf)

[**GitHub Repository**](https://github.com/tobanteAudio/juce-cookbook)

## Content

- [Intro](#intro)
  * [Why did I write this](#why-did-i-write-this)
  * [About myself](#about-myself)
- [Disclaimer](#disclaimer)
- [Code license](#code-license)
- [Contribute](#contribute)
- [How to read](#how-to-read)
- [How to run examples](#how-to-run-examples)
  * [Windows & macOS](#windows---macos)
  * [Linux](#linux)
- [Why JUCE](#why-juce)
  * [Features](#features)
    + [Audio](#audio)
    + [Mobil](#mobil)
- [Other libraries](#other-libraries)
  * [QT](#qt)
  * [SFML](#sfml)
  * [IMGUI](#imgui)
- [Online resources](#online-resources)
  * [Tutorials](#tutorials)
  * [Docs & Forum](#docs---forum)
  * [YouTube](#youtube)
    + [ADC Talks](#adc-talks)
    + [The Audio Programmer](#the-audio-programmer)
      - [Discord](#discord)
- [C++](#c--)
  * [New to C++](#new-to-c--)
  * [Modern standard](#modern-standard)
  * [Resources](#resources)
    + [TheCherno](#thecherno)
    + [Conferences](#conferences)
    + [CppWeekly](#cppweekly)
    + [Books](#books)
  * [Idioms](#idioms)
  * [Tools](#tools)
    + [IDE](#ide)
    + [compiler](#compiler)
    + [clang-tidy](#clang-tidy)
    + [clang-format](#clang-format)
    + [compiler-explorer](#compiler-explorer)
    + [coverage](#coverage)
    + [sanitizers](#sanitizers)
    + [Makefile/Scripts](#makefile-scripts)
- [Getting Started](#getting-started)
  * [Project Types](#project-types)
  * [Project Setup](#project-setup)
    + [Projucer](#projucer)
    + [CMake](#cmake)
  * [Project Run/Debugging](#project-run-debugging)
  * [Project management](#project-management)
  * [Project Documentation](#project-documentation)
  * [Platforms](#platforms)
  * [Project Check-List](#project-check-list)
- [UI](#ui)
- [DSP](#dsp)
- [MVC](#mvc)
- [File IO](#file-io)
- [Network IO](#network-io)
- [OpenGL](#opengl)
- [3rd Party Modules](#3rd-party-modules)
- [Testing](#testing)
  * [JUCE unit tests](#juce-unit-tests)
  * [Catch2](#catch2)
  * [pluginval](#pluginval)
  * [Valgrind](#valgrind)
- [Continuous integration](#continuous-integration)
  * [Travis CI](#travis-ci)
  * [Appveyor](#appveyor)
  * [Deploy](#deploy)
- [Publish](#publish)
- [My wish list for JUCE](#my-wish-list-for-juce)
- [What next](#what-next)
- [Related resources](#related-resources)
- [License](#license)

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

## How to read

Each chapter can be read individually, feel free to jump around and find sections that are of interest to you.

## How to run examples

All of the example projects included in this repository are normal `Projucer` projects, so running them is the same as any other project created with the `Projucer`

- Download JUCE
- Build the Projucer

### Windows & macOS

- Open example projects `.jucer` file & save to generate the build files
- Open the project in your IDE (Visual Studio / XCode)
- Build

### Linux

Make sure you add `Projucer` to your `PATH`.

```sh
cd $PROJECT_ROOT
Projucer --resave $PROJECT_NAME.jucer
cd Builds/LinuxMakefile
make config=[Release, Debug] -j8
```

## Why JUCE

### Features

Long story short, JUCE is a library which solves many common problems a developer might face during the creation of any kind of application. It hides away a lot of complexity, which normally is not very fun to work with. This includes cross platform window creation, file I/O, networking and so on. JUCE also comes with a collection of user interface widgets, such as buttons, combo boxes, menus, tabbed views and many more. A complete list can be found in the [JUCE documentation](https://docs.juce.com/master/index.html#tag_gui). `Components` as they are called in JUCE form the basis of all user interaction in a JUCE application. The appearance is easily customizable. If the ones provided by JUCE don't fit your needs you can also create your own, just create subclass from the `Compoent` you want to customize and of you go.

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

`The Audio Programmer` is a YouTube channel which almost only does JUCE related development tutorials. He has videos for the basics on getting up & running with the library, introduction to `Components`, an introduction to audio plugin development and interviews with people working in the audio developer industry. Each video is `~20-60min` long.

If you are new to C++ and audio this is a create place to start.

If you are already pretty good in the language and have a basic understanding of audio in the digital world these videos will probably be a little to slow for you.

##### Discord

`The Audio Programmer` also runs a Discord channel for everything related to audio development. I hang around sometimes as well.

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

-  How to run them in a plugin build

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

```text
CREATIVE COMMONS CORPORATION IS NOT A LAW FIRM AND DOES NOT
     PROVIDE LEGAL SERVICES. DISTRIBUTION OF THIS DOCUMENT DOES NOT
     CREATE AN ATTORNEY-CLIENT RELATIONSHIP. CREATIVE COMMONS PROVIDES
     THIS INFORMATION ON AN "AS-IS" BASIS. CREATIVE COMMONS MAKES NO
     WARRANTIES REGARDING THE USE OF THIS DOCUMENT OR THE INFORMATION
     OR WORKS PROVIDED HEREUNDER, AND DISCLAIMS LIABILITY FOR DAMAGES
     RESULTING FROM THE USE OF THIS DOCUMENT OR THE INFORMATION OR
     WORKS PROVIDED HEREUNDER.

Statement of Purpose

The laws of most jurisdictions throughout the world automatically
confer exclusive Copyright and Related Rights (defined below) upon the
creator and subsequent owner(s) (each and all, an "owner") of an
original work of authorship and/or a database (each, a "Work").

Certain owners wish to permanently relinquish those rights to a Work
for the purpose of contributing to a commons of creative, cultural and
scientific works ("Commons") that the public can reliably and without
fear of later claims of infringement build upon, modify, incorporate
in other works, reuse and redistribute as freely as possible in any
form whatsoever and for any purposes, including without limitation
commercial purposes. These owners may contribute to the Commons to
promote the ideal of a free culture and the further production of
creative, cultural and scientific works, or to gain reputation or
greater distribution for their Work in part through the use and
efforts of others.

For these and/or other purposes and motivations, and without any
expectation of additional consideration or compensation, the person
associating CC0 with a Work (the "Affirmer"), to the extent that he or
she is an owner of Copyright and Related Rights in the Work,
voluntarily elects to apply CC0 to the Work and publicly distribute
the Work under its terms, with knowledge of his or her Copyright and
Related Rights in the Work and the meaning and intended legal effect
of CC0 on those rights.

1. Copyright and Related Rights. A Work made available under CC0 may
be protected by copyright and related or neighboring rights
("Copyright and Related Rights"). Copyright and Related Rights
include, but are not limited to, the following:

    the right to reproduce, adapt, distribute, perform, display,
    communicate, and translate a Work; moral rights retained by the
    original author(s) and/or performer(s); publicity and privacy
    rights pertaining to a person's image or likeness depicted in a
    Work; rights protecting against unfair competition in regards to a
    Work, subject to the limitations in paragraph 4(a), below; rights
    protecting the extraction, dissemination, use and reuse of data in
    a Work; database rights (such as those arising under Directive
    96/9/EC of the European Parliament and of the Council of 11 March
    1996 on the legal protection of databases, and under any national
    implementation thereof, including any amended or successor version
    of such directive); and other similar, equivalent or corresponding
    rights throughout the world based on applicable law or treaty, and
    any national implementations thereof.

2. Waiver. To the greatest extent permitted by, but not in
contravention of, applicable law, Affirmer hereby overtly, fully,
permanently, irrevocably and unconditionally waives, abandons, and
surrenders all of Affirmer's Copyright and Related Rights and
associated claims and causes of action, whether now known or unknown
(including existing as well as future claims and causes of action), in
the Work (i) in all territories worldwide, (ii) for the maximum
duration provided by applicable law or treaty (including future time
extensions), (iii) in any current or future medium and for any number
of copies, and (iv) for any purpose whatsoever, including without
limitation commercial, advertising or promotional purposes (the
"Waiver"). Affirmer makes the Waiver for the benefit of each member of
the public at large and to the detriment of Affirmer's heirs and
successors, fully intending that such Waiver shall not be subject to
revocation, rescission, cancellation, termination, or any other legal
or equitable action to disrupt the quiet enjoyment of the Work by the
public as contemplated by Affirmer's express Statement of Purpose.

3. Public License Fallback. Should any part of the Waiver for any
reason be judged legally invalid or ineffective under applicable law,
then the Waiver shall be preserved to the maximum extent permitted
taking into account Affirmer's express Statement of Purpose. In
addition, to the extent the Waiver is so judged Affirmer hereby grants
to each affected person a royalty-free, non transferable, non
sublicensable, non exclusive, irrevocable and unconditional license to
exercise Affirmer's Copyright and Related Rights in the Work (i) in
all territories worldwide, (ii) for the maximum duration provided by
applicable law or treaty (including future time extensions), (iii) in
any current or future medium and for any number of copies, and (iv)
for any purpose whatsoever, including without limitation commercial,
advertising or promotional purposes (the "License"). The License shall
be deemed effective as of the date CC0 was applied by Affirmer to the
Work. Should any part of the License for any reason be judged legally
invalid or ineffective under applicable law, such partial invalidity
or ineffectiveness shall not invalidate the remainder of the License,
and in such case Affirmer hereby affirms that he or she will not (i)
exercise any of his or her remaining Copyright and Related Rights in
the Work or (ii) assert any associated claims and causes of action
with respect to the Work, in either case contrary to Affirmer's
express Statement of Purpose.

4. Limitations and Disclaimers.

    No trademark or patent rights held by Affirmer are waived,
    abandoned, surrendered, licensed or otherwise affected by this
    document.  Affirmer offers the Work as-is and makes no
    representations or warranties of any kind concerning the Work,
    express, implied, statutory or otherwise, including without
    limitation warranties of title, merchantability, fitness for a
    particular purpose, non infringement, or the absence of latent or
    other defects, accuracy, or the present or absence of errors,
    whether or not discoverable, all to the greatest extent
    permissible under applicable law.  Affirmer disclaims
    responsibility for clearing rights of other persons that may apply
    to the Work or any use thereof, including without limitation any
    person's Copyright and Related Rights in the Work. Further,
    Affirmer disclaims responsibility for obtaining any necessary
    consents, permissions or other rights required for any use of the
    Work.  Affirmer understands and acknowledges that Creative Commons
    is not a party to this document and has no duty or obligation with
    respect to this CC0 or use of the Work.
```
