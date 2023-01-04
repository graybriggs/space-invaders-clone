
#include "SDL.h"

#include "counter.h"

Counter::Counter(Uint32 target) :
	last_time(0),
	target_time(target),
	is_ready(false),
	running(false)
{}

void Counter::start() {
	running = true;
	last_time = SDL_GetTicks();
}

void Counter::reset() {
	start();
}

void Counter::update() {
	last_time = SDL_GetTicks();
	if (SDL_GetTicks() >= last_time + target_time) {
		is_ready = true;
	}
}

bool Counter::ready() {
	running = false;
	return is_ready;
}