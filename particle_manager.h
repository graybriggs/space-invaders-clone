#pragma once

#ifndef PARTICLE_MANAGER_HPP
#define PARTICLE_MANAGER_HPP

#include <vector>

class Particle;

class ParticleManager {

public:

	void logic();
	void render() const;

private:

	std::vector<Particle> particles;

};

#endif