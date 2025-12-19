#include "Tremolo.h"

Tremolo::Tremolo()
{
    lfoPhase = 0.0f;
    inverseSampleRate = 0.0f;
}

void Tremolo::prepare(double sampleRate)
{
    inverseSampleRate = 1.0f / sampleRate;
    lfoPhase = 0.0f;
}

void Tremolo::process(juce::AudioBuffer<float>& buffer, float rate, float depth)
{
    auto totalNumInputChannels  = buffer.getNumChannels();

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float lfoValue = std::sin(lfoPhase);
            float lfoMod = (lfoValue * depth) + (1.0f - depth);
            
            channelData[sample] *= lfoMod;

            lfoPhase += rate * inverseSampleRate * 2 * juce::MathConstants<float>::pi;
            if(lfoPhase >= 2 * juce::MathConstants<float>::pi)
                lfoPhase -= 2 * juce::MathConstants<float>::pi;
        }
    }
}
