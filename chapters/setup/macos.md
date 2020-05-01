# macOS

## Dependencies

| Program  |                  Description                   |     Source      | Comment  |
| :------: | :--------------------------------------------: | :-------------: | :------: |
|  XCode   |                 Compiler & IDE                 |    AppStore     |          |
|  CMake   |              Build file generator              | brew / download | Optional |
|  Ninja   | Build system similar to Makefiles, but faster. | brew / download | Optional |
| xcpretty |    Pretty prints XCode command line output     | brew / download | Optional |

```sh
brew install cmake ninja-build
gem install xcpretty
```

## Install

```sh
git clone https://github/juce-framework/JUCE.git
cd JUCE/extras/Projucer/Builds/MacOS
xcodebuild --project Projucer.xcodeproj --configuration Release | xcpretty
```

## Tools

### xcpretty

```sh
xcodebuild [flags] | xcpretty                       # Pretty print
xcodebuild [flags] | tee xcodebuild.log | xcpretty  # Pretty print, but save raw output to file.
```
