

#pragma once

// JUCE
#include "../JuceLibraryCode/JuceHeader.h"

// tobanteAudio
#include "ExampleComponent.h"
#include "PluginProcessor.h"

class BasicanimationAudioProcessorEditor : public AudioProcessorEditor
{
public:
  BasicanimationAudioProcessorEditor(BasicanimationAudioProcessor &);
  ~BasicanimationAudioProcessorEditor();

  void paint(Graphics &) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  BasicanimationAudioProcessor &processor;

  tobanteAudio::ExampleComponent exampleComp;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
      BasicanimationAudioProcessorEditor)
};
