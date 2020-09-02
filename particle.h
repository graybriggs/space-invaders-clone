#pragma once
#ifndef PARTICLE_HPP
#define PARTICLE_HPP


#include "utility.h"

#include <string>
#include <random>

class Particle {

public:
	Particle();

	void reset();
	void setPosition(util::rect r);
	void logic(const double delta);
	void render();

private:

	double xVal, yVal;
	bool alive;
	int lifetime;
	int ticks;

};

#endif