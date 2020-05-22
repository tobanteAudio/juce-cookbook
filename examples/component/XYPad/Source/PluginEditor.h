#pragma once

#include "PluginProcessor.h"

#include "XYPad.h"

namespace tobanteAudio
{
class PluginEditor : public juce::AudioProcessorEditor
{
public:
    PluginEditor(PluginProcessor&);
    ~PluginEditor();

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    PluginProcessor& processor;

    tobanteAudio::XYPad pad_;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginEditor)
};

}  // namespace tobanteAudio
