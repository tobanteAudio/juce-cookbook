# Setup

- [macOS](#macos)
- [Windows](#windows)
- [Linux](#linux)

## macOS

### Dependencies

- XCode (install via AppStore)
- CMake (optional)
- Ninja (optional)
- xcpretty (optional)

### Install

```sh
git clone https://github/juce-framework/JUCE.git
cd JUCE/extras/Projucer/Builds/MacOS
xcodebuild --project Projucer.xcodeproj --configuration Release | xcpretty
```

## Windows

### Dependencies

- Visual Studio (download from Microsoft)
- CMake (optional)

### Install

```sh
git clone https://github/juce-framework/JUCE.git
```

- Open `JUCE/extras/Projucer/Builds/VisualStudio2019/Projucer.sln`
- Build in `Release` mode

## Linux

### Dependencies

- CMake (optional)
- Ninja (optional)

### Install

```sh
git clone https://github/juce-framework/JUCE.git
cd JUCE/extras/Projucer/Builds/LinuxMakefile
make config=Release -j8
```
