# macOS

## Dependencies

|                           Program                           |                  Description                   |     Source      | Comment  |
| :---------------------------------------------------------: | :--------------------------------------------: | :-------------: | :------: |
| [XCode](https://apps.apple.com/app/xcode/id497799835?mt=12) |                 Compiler & IDE                 |    AppStore     |          |
|                 [CMake](https://cmake.org)                  |              Build file generator              | brew / download | Optional |
|              [Ninja](https://ninja-build.org)               | Build system similar to Makefiles, but faster. | brew / download | Optional |
|      [xcpretty](https://github.com/xcpretty/xcpretty)       |    Pretty prints XCode command line output     | brew / download | Optional |

## Install

The minimum setup, you'll need for writing JUCE applications, consists of 3 parts: Xcode as your compiler and IDE, the Projucer for creating and managing JUCE projects. and the JUCE library, so you can include the headers in your source code.

### Xcode

Xcode is Apples in-house IDE. The same that Visual Studio is to Windows. Xcode is free for personal and professional use. So no fees required. The only thing that you will need, is an Apple Computer that is signed in to your Apple ID. If that's the case you can simply search for [Xcode on the AppStore](https://apps.apple.com/app/xcode/id497799835?mt=12) and start downloading. This may take a while, depending on your internet connection, since it needs to download around 10 gigabytes.

### JUCE via download

Go to the [JUCE website](https://shop.juce.com/get-juce). Find the most recent version for `macOS` and download the zip file. Afterwards you should extract it to some place of your liking. Your home directory or application folder would be good options.

### JUCE via git

```sh
git clone https://github/juce-framework/JUCE.git
cd JUCE/extras/Projucer/Builds/MacOS
xcodebuild --project Projucer.xcodeproj --configuration Release | xcpretty
```

### Projucer from the command line

If you want to run the Projucer and Xcode from the command line you need to add both to your PATH environment variable. Up until macOS 10.15 **bash** is set as the default shell. With Catalina Apple switched to **zsh**. The syntax for adding environment variables is the same for both shells. You just need to pick the correct configuration file:

```sh
nano ~/.bashrc
nano ~/.zshrc
```

Add your location:

```sh
export PATH=/path/to/Projucer.app/Contents/MacOS:$PATH
```

Reload the environment:

```sh
source ~/.bashrc
source ~/.zshrc
```

## Tools

### Homebrew

Homebrew is a package manager for the mac operating system. If you have ever worked on Linux before, this should be very familiar to you. If you have never heard the term "package manager" before, don't worry! Think of it as an app store on your command line, after installing it from the [website](https://brew.sh) you can run this single line in your terminal to install almost all the tools that we will need.

```sh
brew install doxygen clang-format clang-tidy cmake ninja-build
```

We will take a closer look at these tools in later chapters.

### xcpretty

xcpretty's job, is to pretty print the command line output from Xcode. By default, the output is very verbose. xcpretty cleans this up.

```sh
gem install xcpretty
```

```sh
xcodebuild [flags] | xcpretty                       # Pretty print
xcodebuild [flags] | tee xcodebuild.log | xcpretty  # Pretty print, but save raw output to file.
```
