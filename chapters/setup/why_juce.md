# Why JUCE

## Features

Long story short, JUCE is a library which solves many common problems a developer might face during the creation of any kind of application. It hides away a lot of complexity, which normally is not very fun to work with. This includes cross platform window creation, file I/O, networking and so on. JUCE also comes with a collection of user interface widgets, such as buttons, combo boxes, menus, tabbed views and many more. A complete list can be found in the [JUCE documentation](https://docs.juce.com/master/index.html#tag_gui). `Components` as they are called in JUCE form the basis of all user interaction in a JUCE application. The appearance is easily customizable. If the ones provided by JUCE don't fit your needs you can also create your own, just create subclass from the `Compoent` you want to customize and of you go.

### Audio

- Wraps all common plugin types.
- Basic DSP & Analysis
- Vector instructions for x86 and ARM

### Mobil

- Easily use C++ for both Android & iOS
- Use native features
