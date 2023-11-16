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
		Oscillator noise;
		Oscillator lfo;

		Envelope osc1Env;
		Envelope osc2Env;
		Envelope filterEnv;

	protected:
		static void _bind_methods();

	public:
		Voicing();
		~Voicing();

		void _ready();
		void _process(double _delta);

		void press(int key); // TODO keyFrequency LUT
		void release();

		double sampleRate;

		// TODO
		bool pressed;

		// TODO keys enum
		int osc1Brkpt;
		int osc2Brkpt;
		int osc3Brkpt;

		// TODO curve enum
		int osc1BrkptLCurve;
		int osc2BrkptLCurve;
		int osc3BrkptLCurve;

		int osc1BrkptLCurveDpt;
		int osc2BrkptLCurveDpt;
		int osc3BrkptLCurveDpt;

		// TODO curve enum
		int osc1BrkptRCurve;
		int osc2BrkptRCurve;
		int osc3BrkptRCurve;

		int osc1BrkptRCurveDpt;
		int osc2BrkptRCurveDpt;
		int osc3BrkptRCurveDpt;

		// TODO curve enum
		int filterBrkptRCurve;
		int filterBrkptRCurve;
			
		int filterBrkptRCurveDpt;
		int filterBrkptRCurveDpt;

		int osc1Octave;
		int osc2Octave;

		double osc1FixedFreq;
		double osc2FixedFreq;

		int osc1FreqRatio;
		int osc2FreqRatio;

		int osc1Lvl;
		int osc2Lvl;
		int osc3Lvl;
		int noiseLvl;
		int lfoLvl;

		int mainEnvAtkLvl;
		int mainEnvAtkSpd;
		int mainEnvDecLvl;
		int mainEnvDecSpd;
		int mainEnvSusLvl;
		int mainEnvSusSpd;
		int mainEnvRelLvl;
		int mainEnvRelSpd;

		int filterEnvAtkLvl;
		int filterEnvAtkSpd;
		int filterEnvDecLvl;
		int filterEnvDecSpd;
		int filterEnvSusLvl;
		int filterEnvSusSpd;
		int filterEnvRelLvl;
		int filterEnvRelSpd;
	};

}

#endif