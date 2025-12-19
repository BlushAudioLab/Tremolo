#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_core/juce_core.h>

class Tremolo
{
public:
    Tremolo();
    
    void prepare(double sampleRate);
    
    void process(juce::AudioBuffer<float>& buffer, float rate, float depth);
    
private:
    float lfoPhase;
    float inverseSampleRate;
};
