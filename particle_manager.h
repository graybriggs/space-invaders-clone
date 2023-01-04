#pragma once

#ifndef PARTICLE_MANAGER_HPP
#define PARTICLE_MANAGER_HPP

#include "timer.h"
#include "particle.h"

#include <vector>

#include "SDL.h"

class ParticleManager {
public:
	ParticleManager();
	void fire_from_point(int x, int y);
	void logic(double delta);
	//void render(SDL_Renderer* rend) const;
	std::vector<Particle>& getParticles();

private:
	CountDownTimer cdt;
	std::vector<Particle> particles;
	bool done;
};


#endif