#include "oscillator.h"

Oscillator::Oscillator() {
	currentPhase = 0.0;
	phaseIncrement = 0.0;
	sampleRate = 0.0;
	frequency = 0.0;
	modulation = 0.0;
}

double Oscillator::sine() {
	return sin(phase() + modulation);
}

void Oscillator::updateSettings() {
	phaseIncrement = 1.0 / (sampleRate / frequency);
}

double Oscillator::phase() {
	currentPhase = fmod(currentPhase + phaseIncrement, 1.0);
	return currentPhase * tau;
}