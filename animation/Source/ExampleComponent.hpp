#pragma once

#include "JuceHeader.h"

namespace tobanteAudio
{
class ExampleComponent : public AnimatedAppComponent
{
public:
    ExampleComponent();
    ~ExampleComponent();

    void paint(Graphics&) override;
    void resized() override;

    void update() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExampleComponent)
};

}  // namespace tobanteAudio