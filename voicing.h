#pragma once
#ifndef VOICING_H
#define VOICING_H

#include <godot_cpp/classes/node.hpp>

#include "envelope.h"
#include "oscillator.h"

namespace godot {

	class Voicing : public Node {
		GDCLASS(Voicing, Node)

	private:
		double deltaTime;

		Oscillator oscillator1;
		Oscillator oscillator2;
		Oscillator oscillator3;
		Oscillator oscillator4;

		Envelope envelope1;
		Envelope envelope2;
		Envelope envelope3;
		Envelope envelope4;

	protected:
		static void _bind_methods();

	public:
		Voicing();
		~Voicing();

		void _process(double delta);

		// TODO
		int algorithm;

		bool pressed;

		bool osc1Mute;
		bool osc2Mute;
		bool osc3Mute;
		bool osc4Mute;

		// TODO keys enum
		int osc1BrkPt;
		int osc2BrkPt;
		int osc3BrkPt;
		int osc4BrkPt;

		// TODO curve enum
		int osc1BrkPtLCurve;
		int osc2BrkPtLCurve;
		int osc3BrkPtLCurve;
		int osc4BrkPtLCurve;

		int osc1BrkPtLCurveDpt;
		int osc2BrkPtLCurveDpt;
		int osc3BrkPtLCurveDpt;
		int osc4BrkPtLCurveDpt;

		// TODO curve enum
		int osc1BrkPtRCurve;
		int osc2BrkPtRCurve;
		int osc3BrkPtRCurve;
		int osc4BrkPtRCurve;

		int osc1BrkPtRCurveDpt;
		int osc2BrkPtRCurveDpt;
		int osc3BrkPtRCurveDpt;
		int osc4BrkPtRCurveDpt;

		// TODO keys enum
		int osc1InputNote;
		int osc2InputNote;
		int osc3InputNote;
		int osc4InputNote;

		double osc1FixedFreq;
		double osc2FixedFreq;
		double osc3FixedFreq;
		double osc4FixedFreq;

		int osc1FreqRatio;
		int osc2FreqRatio;
		int osc3FreqRatio;
		int osc4FreqRatio;

		int osc1FreqFine;
		int osc2FreqFine;
		int osc3FreqFine;
		int osc4FreqFine;

		int osc1FreqDetune;
		int osc2FreqDetune;
		int osc3FreqDetune;
		int osc4FreqDetune;

		int osc1Lvl;
		int osc2Lvl;
		int osc3Lvl;
		int osc4Lvl;

		int osc1EnvAtkLvl;
		int osc1EnvAtkSpd;
		int osc1EnvDecLvl;
		int osc1EnvDecSpd;
		int osc1EnvSusLvl;
		int osc1EnvSusSpd;
		int osc1EnvRelLvl;
		int osc1EnvRelSpd;

		int osc2EnvAtkLvl;
		int osc2EnvAtkSpd;
		int osc2EnvDecLvl;
		int osc2EnvDecSpd;
		int osc2EnvSusLvl;
		int osc2EnvSusSpd;
		int osc2EnvRelLvl;
		int osc2EnvRelSpd;

		int osc3EnvAtkLvl;
		int osc3EnvAtkSpd;
		int osc3EnvDecLvl;
		int osc3EnvDecSpd;
		int osc3EnvSusLvl;
		int osc3EnvSusSpd;
		int osc3EnvRelLvl;
		int osc3EnvRelSpd;

		int osc4EnvAtkLvl;
		int osc4EnvAtkSpd;
		int osc4EnvDecLvl;
		int osc4EnvDecSpd;
		int osc4EnvSusLvl;
		int osc4EnvSusSpd;
		int osc4EnvRelLvl;
		int osc4EnvRelSpd;
	};

}

#endif