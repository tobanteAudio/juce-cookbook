# Other Libraries

Of course JUCE is not the only library that helps you build desktop & mobile applications. There are a lot of open source frameworks & libraries that try to achieve similar goals.

The following list is definitely not complete, but should give you a good overview on what is available in the C++ ecosystem.

## QT

- [qt.io](https://www.qt.io/)

If you have been programming with C++ for a while, you probably heard of Qt. It's been around since the mid 90's and is currently being developed by The Qt Company.

The goal of Qt is to do it all. It runs on almost every platform including BSDs and embedded platforms. Because of this the whole framework is huge. While JUCE is around a couple of hundred megabytes, Qt is more in the range of a couple gigabytes.

Qt is also not really designed to help you write audio applications. There is no easy way to wrap a Qt application in an AudioUnit or VST plug-in for example.

If your goal is to write a desktop application in the style of Gimp, FreeCAD or Blender and you need a lot of premade desktop widgets, Qt is probably the way to go.

Qt is free for open source projects, but a license for closed source application can become pretty expensive.

## SFML

- [sfml-dev.org](https://www.sfml-dev.org/)
- [github.com/SFML/SFML](https://github.com/SFML/SFML)

### Summary

- Very simple API
- Intended for games / 2D graphics

## IMGUI

- [github.com/ocornut/imgui](https://github.com/ocornut/imgui)

### Summary

- Not so easy to integrate
- Intended for simple UI widgets
- Works well with SFML, SDL, OpenGL
- Example Projects
  - [github.com/tobanteAudio/moci](https://github.com/tobanteAudio/moci)

## Other

Let me know if you think other libraries should be listed here, but let's keep it at C++ only.
