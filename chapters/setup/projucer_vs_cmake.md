# Projucer vs. CMake

Prior to JUCE version 6, the Projucer is the only official way of creating projects. CMake support is currently available on the `juce6` preview branch.

If you already know how CMake works, this will be your best option. The preview branch is very stable.

## Projucer

- Quick Setup
- Perfect IDE integration
- Hard to link external code/libraries

The Projucer is an application that comes with the JUCE library. It handles the creation if IDE projects and Makefiles depending on the platform. All of your configuration is stored in a `.jucer` file, which internally is xml. Compiler flags, defines & includes can be set for each platform independently. Limitations come when you want to link against third party code. If you get to this point you should probably switch to CMake.

This is definitely the fasted way of creating & running a project.

## CMake

CMake support is coming in JUCE version 6. This will let you simply write `add_subdirectory(path/to/JUCE)` in your CMake configuration.

A guide can be found in the JUCE repository: [github.com/juce-framework/JUCE/tree/juce6/examples/CMake](https://github.com/juce-framework/JUCE/tree/juce6/examples/CMake)

Example plug-in projects can be found here:

- [tobanteAudio/juce-6-demo](https://github.com/tobanteAudio/juce-6-demo)
- [tobanteAudio/modEQ](https://github.com/tobanteAudio/modEQ)
