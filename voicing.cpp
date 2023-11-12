#include "voicing.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Voicing::_bind_methods()
{
}

Voicing::Voicing()
{
	oscillator1.updateSettings();
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
}

void godot::Voicing::_process(double _delta)
{
	for (int i = 0; i < audioStreamGeneratorPlayback->get_frames_available(); i++) {
		audioStreamGeneratorPlayback->push_frame(Vector2(1, 1) * oscillator1.sine());
	}
}

void godot::Voicing::press(int key)
{
}

void godot::Voicing::release()
{
}
