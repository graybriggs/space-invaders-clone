
#include <SDL.h>
#include <cstdio>
#include <iostream>
#include "timer.h"

Timer::~Timer() {}

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

void CountDownTimer::setActive() {
	active = true;
}

bool CountDownTimer::countdown(Uint32 amount) {

	if (active) {
		current_time = SDL_GetTicks();
		if (current_time > last_time + amount) {
			last_time = current_time;
			active = false;
			return true;
		}
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

/*

// target in ms
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

*/