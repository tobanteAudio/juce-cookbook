

#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
BasicanimationAudioProcessorEditor::BasicanimationAudioProcessorEditor(
    BasicanimationAudioProcessor &p)
    : AudioProcessorEditor(&p), processor(p)
{
  setSize(800, 600);
  addAndMakeVisible(exampleComp);
}

BasicanimationAudioProcessorEditor::~BasicanimationAudioProcessorEditor() {}

//==============================================================================
void BasicanimationAudioProcessorEditor::paint(Graphics &g)
{
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void BasicanimationAudioProcessorEditor::resized()
{
  const auto area = getLocalBounds();
  exampleComp.setBounds(area);
}
