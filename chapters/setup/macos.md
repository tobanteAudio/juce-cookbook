# macOS

## Dependencies

| Program  |                  Description                   |     Source      | Comment  |
| :------: | :--------------------------------------------: | :-------------: | :------: |
|  XCode   |                 Compiler & IDE                 |    AppStore     |          |
|  CMake   |              Build file generator              | brew / download | Optional |
|  Ninja   | Build system similar to Makefiles, but faster. | brew / download | Optional |
| xcpretty |    Pretty prints XCode command line output     | brew / download | Optional |

## Install

```sh
brew install cmake ninja-build
gem install xcpretty
```

### Xcode

Xcode is Apples in-house IDE. The same that Visual Studio is to Windows. Xcode is free for personal and professional use. So no fees required. The only thing that you will need, is an Apple Computer that is signed in to your Apple ID. If that's the case you can simply search for Xcode on the AppStore and start downloading. This may take a while, depending on your internet connection, since it needs to download around 10 gigabytes.

### JUCE via download

Go the [JUCE website](https://shop.juce.com/get-juce). Find the most recent version for `macOS` and download the zip file. Afterwards you should extract it to some place of your liking. Your home directory or application folder would be good options.

### JUCE via git

```sh
git clone https://github/juce-framework/JUCE.git
cd JUCE/extras/Projucer/Builds/MacOS
xcodebuild --project Projucer.xcodeproj --configuration Release | xcpretty
```

### Projucer from the command line

If you want to run the Projucer and Xcode from the command line you need to add both to your PATH environment variable. Up until macOS 10.15 `bash` is set as the default shell. With Catalina Apple switched to `zsh`. The syntax for adding environment variables is the same for both shells. You just need to pick the correct configuration file:

```sh
nano ~/.bashrc
nano ~/.zshrc
```

```sh
export PATH=/path/to/Projucer.app/Contents/MacOS:$PATH
```

## Tools

### xcpretty

xcpretty's job, is to pretty print the command line output from Xcode. By default, the output is very verbose. xcpretty cleans this up.

```sh
xcodebuild [flags] | xcpretty                       # Pretty print
xcodebuild [flags] | tee xcodebuild.log | xcpretty  # Pretty print, but save raw output to file.
```
