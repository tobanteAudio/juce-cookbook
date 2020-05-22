#pragma once

#include <JuceHeader.h>

namespace tobanteAudio
{
class XYPad : public juce::Component
{
public:
    XYPad() = default;

    ~XYPad() override = default;

    void paint(juce::Graphics& g) override
    {
        auto const color = juce::Colour(204, 204, 204);
        g.fillAll(color);

        auto thumb = juce::Rectangle<float> {20, 20};
        thumb.setCentre(data_);
        g.setColour(juce::Colours::black);
        g.fillEllipse(thumb);
    }

    void resized() override
    {
        area_ = getLocalBounds().toFloat();
        data_ = area_.getCentre();
    }

private:
    juce::Point<float> data_ {};
    juce::Rectangle<float> area_ {};
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(XYPad)
};

}  // namespace tobanteAudio
