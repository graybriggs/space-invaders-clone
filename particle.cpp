
#include "particle.h"

#include <random>

Particle::Particle()
{
	std::mt19937 rng;
	rng.seed();
}


void Particle::reset() {

	//std::unitform_int_distribution<int> direction(0,360);

	xVal = (rand() % 100) + 25;
	yVal = (rand() % 100) + 20;

	lifetime = (rand() % 250) + 50;

	ticks = SDL_GetTicks();
}

void Particle::logic(const double delta) {

	xVal += xVal * delta;
	yVal += yVal * delta;

	ticks = SDL_GetTicks();
	if (ticks >= ticks + lifetime) {
		alive = false;
	}

}

void Particle::render() {


}
