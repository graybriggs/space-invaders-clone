#pragma once

#ifndef TIMER_HPP
#define TIMER_HPP



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

#endif


