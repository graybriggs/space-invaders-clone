
#include "particle.h"


#include <random>

Particle::Particle()
{
	std::mt19937 rng;
	rng.seed();
	alive = true;

	SDL_Rect p;
	p.x = 0;
	p.y = 0;
	p.w = 2;
	p.h = 2;
	box = p;
}

void Particle::set_position(int x, int y) {
	box.x = x;
	box.y = y;
}

void Particle::set_position(SDL_Rect pos) {
	box.x = pos.x;
	box.y = pos.y;
}

void Particle::reset() {

	//std::uniform_int_distribution<int> direction(0,360);

	xVal = (rand() % 100) + 25;
	yVal = (rand() % 100) + 20;

	lifetime = (rand() % 250) + 50;

	ticks = SDL_GetTicks();
}

void Particle::logic(const double delta) {

	if (alive) {
		xVal += xVal * delta;
		yVal += yVal * delta;

		ticks = SDL_GetTicks();
	}
	if (ticks >= ticks + lifetime) {
		alive = false;
	}

}

bool Particle::is_alive() const {
	return alive;
}

SDL_Rect Particle::get_box() const {
	return box;
}
