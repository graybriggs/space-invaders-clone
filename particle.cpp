
#include "particle.h"
#include "utility.h"

#include <cstdlib>

Particle::Particle()
	: particle_box(util::Rect(0,0,2,2))
{
	alive = true;

	//SDL_Rect p;
	//p.x = 0;
	//p.y = 0;
	//p.w = 8;
	//p.h = 8;
	////box = p;
	//particle_box.fromSDLRect(p);

	ticks = SDL_GetTicks();
	lifetime = 1000;
	xVal = 0.1;
	yVal = 0.05;
}

void Particle::set_position(int x, int y) {
	//box.x = x;
	//box.y = y;
	particle_box.pos_x = x;
	particle_box.pos_y = y;

}

void Particle::set_position(SDL_Rect pos) {
	//box.x = pos.x;
	//box.y = pos.y;
	particle_box.pos_x = pos.x;
	particle_box.pos_y = pos.y;
}

void Particle::reset() {

	//std::uniform_int_distribution<int> direction(0,360);

	double MAX = 0.1;
	double MIN = -2.0;
	double range = MAX - MIN + 1;
	

	xVal = (double)rand() / (double)RAND_MAX * 3.5;
	yVal = (double)rand() / (double)RAND_MAX * 3.5;

	if (rand() % 2 == 0) {
		xVal *= -1;
	}
	if (rand() % 2 == 0) {
		yVal *= -1;
	}

	particle_box.pos_x += xVal;
	particle_box.pos_y += yVal;

	lifetime = (rand() % 250);

	ticks = SDL_GetTicks();
}

void Particle::logic(const double delta) {

	if (is_alive()) {

		particle_box.pos_x += xVal * delta;
		particle_box.pos_y += yVal * delta;

		ticks = SDL_GetTicks();
	}

	if (ticks >= ticks + lifetime) {
		alive = false;
		reset();
	}

}

bool Particle::is_alive() const {
	return alive;
}

void Particle::set_alive() {
	alive = true;
}

SDL_Rect Particle::get_box() const {
	
	return particle_box.getSDLRect();
}

