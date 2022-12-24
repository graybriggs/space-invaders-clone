#pragma once
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "utility.h"

class Particle {

public:
	Particle();

	void set_position(int x, int y);
	void set_position(SDL_Rect pos);
	void reset();
	void logic(const double delta);
	bool is_alive() const;

	SDL_Rect get_box() const;

private:

	SDL_Rect box;
	double xVal, yVal;
	bool alive;
	int lifetime;
	int ticks;

};

#endif