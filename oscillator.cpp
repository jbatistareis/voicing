#include "oscillator.h"

Oscillator::Oscillator() {
}

double Oscillator::sine(double modulation) {
	phaseIncrement = 1.0 / (sampleRate / frequency);
	return sin(phase() + modulation);
}

double Oscillator::noise()
{
	return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2.0)) - 1.0;
}

double Oscillator::phase() {
	currentPhase = fmod(currentPhase + phaseIncrement, 1.0);
	return currentPhase * tau;
}

double Oscillator::frame(double modulation)
{
	switch (shape)
	{
	case SINE:
		return sine(modulation);

	case SQUARE: {
		double value = sine(modulation);
		return (value < 0) ? -1 : (value > 0) ? 1 : 0;
	}

	case NOISE:
		return noise();

	default:
		return 0.0;
	}
}

double Oscillator::frame()
{
	return frame(0.0);
}