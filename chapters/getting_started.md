# Getting Started

## How to run examples

Each chapter can be read individually, feel free to jump around and find sections that are of interest to you.

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
