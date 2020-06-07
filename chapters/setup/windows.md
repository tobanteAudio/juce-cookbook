# Windows

## Dependencies

|                         Program                         |     Description      |          Source          | Comment  |
| :-----------------------------------------------------: | :------------------: | :----------------------: | :------: |
| [Visual Studio](https://visualstudio.microsoft.com/vs/) |    Compiler & IDE    | Download from Microsoft  |          |
|         [git](https://git-scm.com/download/win)         |   Version Control    | Scoop / Choco / Download |          |
|               [CMake](https://cmake.org)                | Build file generator | Scoop / Choco / Download | Optional |

## Install

The minimum setup, you'll need to start writing JUCE applications on Windows consists of 4 parts: Visual Studio as your compiler and IDE, the Projucer for creating and managing JUCE projects, the JUCE library source, so you can include the headers in your source files and git, which we will to keep track of our project history and also stay up to date on the latest JUCE releases.

### Visual Studio

Visual Studio is Microsoft's in-house IDE. The same that Xcode is to macOS. Visual Studio is free for personal and professional use. So no fees required. You can download the installer from [Microsoft's website](https://visualstudio.microsoft.com/vs/). Run the downloaded program and select the C++ tools and click install. This may take a while, depending on your internet connection, since the downloaded files are around 10 gigabytes in size.

### git

Simply download the [offical installer](https://git-scm.com/download/win), keep all default settings, that's it.

### JUCE via download

Go to the [JUCE website](https://shop.juce.com/get-juce). Find the most recent version for `Windows` and download the zip file. Afterwards you should extract it to some place of your liking. Your home directory or C drive would be good options.

### JUCE via git

```sh
git clone https://github/juce-framework/JUCE.git
```

- Open `JUCE/extras/Projucer/Builds/VisualStudio2019/Projucer.sln`
- Build in `Release` mode

### Package Manager

Like Linux and macOS, Windows has package managers available. They make it easier to install, update and remove applications from your system.

If you're unsure which one to choose, I'd recommend going with Scoop. For me personally it has proven to be the most stable and easy to work with.

#### Scoop

- [Website](https://scoop.sh/)

You can install Scoop, by following the instructions on their website. Not that you may have to run this additional command to allow scripts from remote locations. Powershell should also be launch in admin mode.

After Scoop is installed, you can run the following command to install applications. If you are unsure if Scoop supports the application you are looking for, you can run the search command to find applications, but not install them.

```ps
scoop install doxygen
scoop search doxygen
```

#### Chocolatey

- [Website](https://chocolatey.org/install)

Choco's installation process is almost identical to Scoop. Simply follow the instructions on their website and you're done.

The commands are also identical.

```ps
choco install doxygen
choco search doxygen
```
