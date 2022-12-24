#pragma once

#include "SDL.h"

// class that takes a time
// call start()
// once time is elapsed return callback/boolean value

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