#pragma once

// JUCE
#include "JuceHeader.h"

// tobanteAudio
#include "ExampleComponent.hpp"
#include "PluginProcessor.hpp"

class BasicanimationAudioProcessorEditor : public AudioProcessorEditor
{
public:
    BasicanimationAudioProcessorEditor(BasicanimationAudioProcessor&);
    ~BasicanimationAudioProcessorEditor();

    void paint(Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicanimationAudioProcessor& processor;

    tobanteAudio::ExampleComponent exampleComp;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BasicanimationAudioProcessorEditor)
};
