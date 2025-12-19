#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AudioPluginAudioProcessor& processorRef;

    juce::Slider rateSlider;
    juce::Label rateLabel;
    juce::Slider depthSlider;
    juce::Label depthLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rateAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> depthAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
