#include "voicing.h"


using namespace godot;

void Voicing::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("press"), &Voicing::press);
	ClassDB::bind_method(D_METHOD("release"), &Voicing::release);
}

Voicing::Voicing()
{
	oscillator3.shape = Oscillator::SQUARE;
	noiseOscillator.shape = Oscillator::NOISE;
}

Voicing::~Voicing()
{
	delete audioStreamGeneratorPlayback;
}

void godot::Voicing::_ready()
{
	set_stream(new AudioStreamGenerator());
	play();

	audioStreamGeneratorPlayback = (AudioStreamGeneratorPlayback*)*get_stream_playback();

	// TEST
	press(0);
}

// TODO envelope influence, waveshape
void godot::Voicing::_process(double _delta)
{
	for (int i = 0; i < audioStreamGeneratorPlayback->get_frames_available(); i++) {
		sampleRate = ((AudioStreamGenerator*)*get_stream())->get_mix_rate();
		oscillator1.sampleRate = sampleRate;
		oscillator2.sampleRate = sampleRate;
		oscillator3.sampleRate = sampleRate;
		lfo.sampleRate = sampleRate;

		// TODO fine tune, octave change
		oscillator1.frequency = currFreq;
		oscillator2.frequency = currFreq;
		oscillator3.frequency = currFreq * 0.5;
		lfo.frequency = linScaling[lfoFreq] * 100.0;
		
		lfoFrame = lfo.frame();
		whlLerp = (2.0 * linScaling[whlPos]) - 1.0;
		whlFreqModVal = whlLerp * linScaling[whlFreqMod];
		whlFilterModVal = whlLerp * linScaling[whlFilterMod];
		whlWaveModVal = whlLerp * linScaling[whlWaveMod];

		finalFrame =
			exp3Scaling[mainLvl] * 
			(
				(exp3Scaling[osc1Lvl] * oscillator1.frame(lfoFrame + whlFreqModVal)) +
				(exp3Scaling[osc2Lvl] * oscillator2.frame(lfoFrame + whlFreqModVal)) +
				(exp3Scaling[osc3Lvl] * oscillator3.frame(lfoFrame + whlFreqModVal)) +
				(exp3Scaling[noiseLvl] * noiseOscillator.frame())
				);

		audioStreamGeneratorPlayback->push_frame(VECTOR2_ONE * finalFrame);
	}
}

void godot::Voicing::press(int key)
{
	prevKey = currKey;
	currKey = key;

	currFreq = keyFrequency[currKey]; // TODO fixed octave, glide
}

void godot::Voicing::release()
{
}
