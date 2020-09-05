
#include <SDL.h>

#include "timer.h"

void Timer::start() {
	float accumulator = 0.0f;
	float frameStart = static_cast<float>(SDL_GetTicks());
}

void Timer::beginFrame() {
	const float currentTime = static_cast<float>(SDL_GetTicks());
	accumulator += currentTime - frameStart;
	frameStart = currentTime;
}

float Timer::getDeltaTime() const {
	return dt;
}

void Timer::update() {
	accumulator -= dt;
}


