#include "voicing.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Voicing::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("press"), &Voicing::press);
	ClassDB::bind_method(D_METHOD("release"), &Voicing::release);
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
		audioStreamGeneratorPlayback->push_frame(VECTOR2_ONE * oscillator1.sine());
	}
}

void godot::Voicing::press(int key)
{
}

void godot::Voicing::release()
{
}
