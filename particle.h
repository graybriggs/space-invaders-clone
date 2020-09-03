#pragma once
#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "utility.h"

class Particle {

public:
	Particle();

	void reset();
	void setPosition(SDL_Rect r);
	void logic(const double delta);
	void render();

private:

	double xVal, yVal;
	bool alive;
	int lifetime;
	int ticks;

};

#endif