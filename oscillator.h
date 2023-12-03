#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

class Oscillator {

private:
	const double tau = M_PI * 2.0;
	double currentPhase = 0.0;
	double phaseIncrement = 0.0;

	double phase();

	double noise();
	double sine(double modulation); // TODO saw, square
	
public:
	enum waveShape { SINE, SQUARE, SAW_UP, SAW_DOWN, NOISE };

	double sampleRate = 44100.0;
	double frequency = 440.0;
	waveShape shape = SINE;

	Oscillator();
	double frame();
	double frame(double modulation);
	
};