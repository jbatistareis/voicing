#pragma once
#ifndef VOICING_H
#define VOICING_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

	class Voicing : public Sprite2D {
		GDCLASS(Voicing, Sprite2D)

	private:
		double time_passed;

	protected:
		static void _bind_methods();

	public:
		Voicing();
		~Voicing();

		void _process(double delta);
	};

}

#endif