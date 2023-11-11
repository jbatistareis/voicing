#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Oscillator {

private:
	const double tau = M_PI * 2.0;
	double currentPhase;
	double phaseIncrement;

	double phase();
	
public:
	double sampleRate;
	double frequency;
	double modulation;

	Oscillator();
	void updateSettings();
	double sine(); // TODO saw, square

};