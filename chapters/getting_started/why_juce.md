# Why JUCE

## Features

Long story short, JUCE is a library which solves many common problems a developer might face during the creation of any kind of application. It hides away a lot of complexity, which normally is not very fun to work with. This includes cross platform window creation, file I/O, networking and so on. JUCE also comes with a collection of user interface widgets, such as buttons, combo boxes, menus, tabbed views and many more. A complete list can be found in the [JUCE documentation](https://docs.juce.com/master/index.html#tag_gui). `Components` as they are called in JUCE form the basis of all user interaction in a JUCE application. The appearance is easily customizable. If the ones provided by JUCE don't fit your needs you can also create your own, just create subclass from the [`juce::Component`](https://docs.juce.com/master/classComponent.html) you want to customize and of you go.

### Graphics

- Easy to use UI components
  - [Label](https://docs.juce.com/master/classLabel.html)
  - Buttons ([Text](https://docs.juce.com/master/classTextButton.html), [Toogle](https://docs.juce.com/master/classToggleButton.html) & ...)
  - [Slider](https://docs.juce.com/master/classSlider.html)
  - [Combobox](https://docs.juce.com/master/classComboBox.html)
  - [TabbedView](https://docs.juce.com/master/classTabbedComponent.html)
  - and more...

### Audio

- Wraps all common plug-in types.
  - VST3
  - AU
  - AAX
  - UNITY
  - LADSPA
- [DSP Building Blocks](https://docs.juce.com/master/tutorial_dsp_introduction.html)
  - [Gain](https://docs.juce.com/master/classdsp_1_1Gain.html)
  - [Filters (IIR, FIR, StateVariable)](https://docs.juce.com/master/group__juce__dsp-processors.html)
  - Panner
  - [Reverb](https://docs.juce.com/master/classdsp_1_1Reverb.html) (Freevrb Implementation)
  - [Oscillator](https://docs.juce.com/master/classdsp_1_1Oscillator.html)
  - [Waveshaper](https://docs.juce.com/master/structdsp_1_1WaveShaper.html)
  - [Convoluation](https://docs.juce.com/master/classdsp_1_1Convolution.html)
  - [Oversampling](https://docs.juce.com/master/classdsp_1_1Oversampling.html)
  - [Many math functions](https://docs.juce.com/master/group__juce__dsp-maths.html)
- Analysis
  - RMS & Peak
  - [FFT](https://docs.juce.com/master/classdsp_1_1FFT.html)
- Vector instructions (SIMD) for x86_64 and ARM
  - [SIMDWrapper](https://docs.juce.com/master/structdsp_1_1SIMDRegister.html)

### Mobil

- Easily use C++ for both Android & iOS
- Use native features
