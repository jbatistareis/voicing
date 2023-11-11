#include "voicing.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Voicing::_bind_methods() {
}

Voicing::Voicing() {
	deltaTime = 0.0;
}

Voicing::~Voicing() {
}

void Voicing::_process(double delta) {
	deltaTime = delta;
}