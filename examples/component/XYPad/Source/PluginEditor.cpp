#include "PluginEditor.h"

namespace tobanteAudio
{
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p), processor(p)
{
    setSize(400, 300);
}

PluginEditor::~PluginEditor() { }

void PluginEditor::paint(juce::Graphics& g)
{
    auto const color = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId);
    g.fillAll(color);
}

void PluginEditor::resized() { }

}  // namespace tobanteAudio