#pragma once
#ifndef VOICING_H
#define VOICING_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/audio_stream_generator.hpp>
#include <godot_cpp/classes/audio_stream_generator_playback.hpp>
#include <godot_cpp/core/class_db.hpp>

#include "oscillator.h"
#include "envelope.h"
#include "lookupTables.h"

namespace godot {

	class Voicing : public AudioStreamPlayer {
		GDCLASS(Voicing, AudioStreamPlayer)

	private:
		const Vector2 VECTOR2_ONE = Vector2(1, 1);

		AudioStreamGeneratorPlayback* audioStreamGeneratorPlayback;

		Oscillator oscillator1;
		Oscillator oscillator2;
		Oscillator oscillator3;
		Oscillator noiseOscillator;
		Oscillator lfo;

		Envelope osc1Env;
		Envelope osc2Env;
		Envelope filterEnv;

		double sampleRate = 44100.0;

		bool pressed;

		int currKey = 0;
		int prevKey = 0;
		double currFreq = 440.0;

		double noiseFrame = 0.0;
		double lfoFrame = 0.0;
		double finalFrame = 0.0;

		double whlFreqModVal = 0.0;
		double whlFilterModVal = 0.0;
		double whlWaveModVal = 0.0;

	protected:
		static void _bind_methods();

	public:
		Voicing();
		~Voicing();

		void _ready();
		void _process(double _delta);

		void press(int key); // TODO keyFrequency LUT
		void release();

		int freqFine;

		int glideRate;

		int osc1Shape;
		int osc2Shape;
		int lfoShape;

		int mainOctave;
		int osc1Octave;
		int osc2Octave;

		int lfoFreq = 0;

		int whlPos = 64;
		double whlLerp = 0;

		int whlFreqMod = 0;
		int whlFilterMod = 0;
		int whlWaveMod = 0; // TODO figure out

		bool pithModOsc2;

		int mainLvl = 127;
		int osc1Lvl = 127;
		int osc2Lvl = 127;
		int osc3Lvl = 127;
		int noiseLvl = 0;

		int mainEnvAtkSpd;
		int mainEnvDecSpd;
		int mainEnvSusLvl;
		int mainEnvRelSpd;

		int filterEnvAtkSpd;
		int filterEnvDecSpd;
		int filterEnvSusLvl;
		int filterEnvRelSpd;
	};

}

#endif