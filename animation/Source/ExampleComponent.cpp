#include "ExampleComponent.hpp"

namespace tobanteAudio
{
ExampleComponent::ExampleComponent() { setFramesPerSecond(60); }

ExampleComponent::~ExampleComponent() {}

void ExampleComponent::paint(Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a
    // solid colour)
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

    g.setColour(getLookAndFeel().findColour(Slider::thumbColourId));

    const auto fishLength = 15;

    Path spinePath;

    for (auto i = 0; i < fishLength; ++i)
    {
        const auto radius = 100 + 10 * std::sin(getFrameCounter() * 0.1f + i * 0.5f);

        const Point<float> p(getWidth() / 2.0f + 1.5f * radius * std::sin(getFrameCounter() * 0.02f + i * 0.12f),
                             getHeight() / 2.0f + 1.0f * radius * std::cos(getFrameCounter() * 0.04f + i * 0.12f));

        // draw the circles along the fish
        g.fillEllipse(p.x - i, p.y - i, 2.0f + 2.0f * i, 2.0f + 2.0f * i);

        if (i == 0)
            spinePath.startNewSubPath(p);  // if this is the first point, start a new path..
        else
            spinePath.lineTo(p);  // ...otherwise add the next point
    }

    // draw an outline around the path that we have created
    g.strokePath(spinePath, PathStrokeType(4.0f));
}

void ExampleComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}
void ExampleComponent::update() {}

}  // namespace tobanteAudio