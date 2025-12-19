#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    rateAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processorRef.apvts, "RATE", rateSlider);
    depthAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processorRef.apvts, "DEPTH", depthSlider);

    rateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    depthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);

    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    depthSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);

    rateLabel.setText("Rate", juce::dontSendNotification);
    depthLabel.setText("Depth", juce::dontSendNotification);

    addAndMakeVisible(rateSlider);
    addAndMakeVisible(rateLabel);
    addAndMakeVisible(depthSlider);
    addAndMakeVisible(depthLabel);

    setSize (400, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() // NOLINT(*-use-equals-default)
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::teal);
}

void AudioPluginAudioProcessorEditor::resized()
{
    const int sliderWidth = 150;
    const int sliderHeight = 150;
    const int labelHeight = 20;
    const int border = 20;

    rateLabel.setBounds(border, border, sliderWidth, labelHeight);
    rateSlider.setBounds(border, border + labelHeight, sliderWidth, sliderHeight);

    depthLabel.setBounds(getWidth() - sliderWidth - border, border, sliderWidth, labelHeight);
    depthSlider.setBounds(getWidth() - sliderWidth - border, border + labelHeight, sliderWidth, sliderHeight);
}
