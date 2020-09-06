
#include <SDL.h>
#include <cstdio>
#include <iostream>
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


////

void CountDownTimer::update() {
	current_time = SDL_GetTicks();
}

bool CountDownTimer::countdown(Uint32 amount) {

	current_time = SDL_GetTicks();
	if (current_time > last_time + amount) {
		// a second has elapsed
		//std::cout << "Report: " << variable << "\n";
		last_time = current_time;
		return true;
	}
	return false;
}

bool CountDownTimer::oneSecond() {
	current_time = SDL_GetTicks();
	if (current_time > last_time + 1000) {
		// a second has elapsed
		//std::cout << "Report: " << current_time << "\n";
		//fprintf(stderr, "%d", current_time);
		last_time = current_time;
		return true;
	}
	return false;
}

