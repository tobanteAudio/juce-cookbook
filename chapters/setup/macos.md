# macOS

## Dependencies

- XCode (install via AppStore)
- CMake (optional)
- Ninja (optional)
- xcpretty (optional)

## Install

```sh
git clone https://github/juce-framework/JUCE.git
cd JUCE/extras/Projucer/Builds/MacOS
xcodebuild --project Projucer.xcodeproj --configuration Release | xcpretty
```
