# Code snippets

## Plug-in recall

Variable `parameters_` is of type `juce::AudioProcessorValueTreeState`:

```cpp
void YourPluginProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    juce::MemoryOutputStream stream(destData, false);
    parameters_.state.writeToStream(stream);
}

void YourPluginProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    juce::ValueTree tree = juce::ValueTree::readFromData(data, static_cast<size_t>(sizeInBytes));
    jassert(tree.isValid());
    if (tree.isValid())
    {
        parameters_.state = tree;
    }
}
```
