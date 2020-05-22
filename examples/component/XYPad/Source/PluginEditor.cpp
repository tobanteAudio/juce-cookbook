#include "PluginEditor.h"

namespace tobanteAudio
{
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p), processor(p)
{
    addAndMakeVisible(pad_);
    setSize(400, 300);
}

PluginEditor::~PluginEditor() { }

void PluginEditor::paint(juce::Graphics& g)
{
    // auto const color = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId);
    auto const color = juce::Colour(244, 244, 244);
    g.fillAll(color);
}

void PluginEditor::resized()
{
    auto area = getLocalBounds();
    pad_.setBounds(area.reduced(10));
}

}  // namespace tobanteAudio