# pluginval

[github.com/Tracktion/pluginval](https://github.com/Tracktion/pluginval)

- [Checks](#checks)
- [Install](#install)
- [GUI](#gui)
- [Command Line](#command-line)

The `pluginval` team describes there software as:

```text
pluginval is a cross-platform plugin validator and tester application.
It is designed to be used by both plugin and host developers
to ensure stability and compatibility between plugins and hosts.
```

You can run `pluginval` both in command-line or GUI mode. So it's very easy to integrate into yout `CI` pipeline.

## Checks

- Randomly automate UI/parameters
- Recall parameters
- Call audio callback with different sample rates & buffer sizes
- Checking for memory allocations on audio thread (macOS AU only)
- And more...

## Install

The simplest way to get pluginval is to download it directly from GitHub. See the [releases page](https://github.com/Tracktion/pluginval/releases).

### macOS

```sh
curl -L "https://github.com/Tracktion/pluginval/releases/download/latest_release/pluginval_macOS.zip" -o pluginval.zip
unzip pluginval
cp -r pluginval.app ~/Applications
```

### Windows

TODO

### Linux

```sh
curl -L "https://github.com/Tracktion/pluginval/releases/download/latest_release/pluginval_linux.zip" -o pluginval.zip
unzip pluginval
cp pluginval /usr/local/bin
```

## GUI

Should be the same an all platforms:

- Launch `pluginval`
- Scan for plug-ins
- Set strictness
- Select plug-in to test
- Test

## Command Line

### macOS

```sh
~/Applications/pluginval.app/Contents/MacOS/pluginval --validate-in-process --strictness-level 10 --validate "path/to/your.vst3" || exit 1
```

### Windows

Somehow `pluginval` doesn't like `powershell`, so `cmd` should be used or run it in GUI mode.

### Linux

```sh
pluginval --validate-in-process --strictness-level 10 --validate "path/to/your.vst3" || exit 1
```
