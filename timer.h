#pragma once

#ifndef TIMER_HPP
#define TIMER_HPP

#include "SDL.h"

class Timer {

public:

	void start();
	void beginFrame();
	float getDeltaTime() const;
	void update();

	~Timer();

private:
	const float fps = 60.0f;
	const float dt = 1.0f / fps;
	float accumulator;
	float frameStart;
};

/////////////////////////////////

class CountDownTimer {
public:

	void update();
	bool countdown(Uint32 amount);
	bool oneSecond();
	void setActive();

private:

	bool active;
	Uint32 current_time;
	Uint32 last_time;
};

////////////////////////////////

// class that takes a time
// call start()
// once time is elapsed return callback/boolean value

/*

class Counter {
public:
	Counter(Uint32 target); // target in ms

	void start();
	void reset();
	void update();
	bool ready();

private:
	bool running;
	bool is_ready;
	Uint32 last_time;
	Uint32 target_time;
};

*/

#endif


