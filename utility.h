#pragma once

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SDL.h>

#include <memory>

namespace util {

	struct rect {

		rect(float x_, float y_, float w_, float h_)
			: x(x_), y(y_), w(w_), h(h_) {}

		float x, y;
		float w, h;
	};

	// these functions are defined as inline to avoid breaking the
	// C++ "one defintion rule"

	inline void rectToSDLRect(const rect& r, SDL_Rect& sdlrect) {

		sdlrect.x = Uint32(r.x);
		sdlrect.y = Uint32(r.y);
		sdlrect.w = Uint32(r.w);
		sdlrect.h = Uint32(r.h);
	}

	inline bool collisionRectScreenLeft(const rect r, int left) {

		int result = static_cast<int>(r.x);

		if (result < left)
			return true;
		else
			return false;
	}

	inline bool collisionRectScreenRight(const rect r, int right) {

		int result = static_cast<int>(r.x + r.w);

		if (result >= right)
			return true;
		else
			return false;
	}

	// standard axis aligned collision detection algorithm
	inline bool aabbCollision(const rect& a, const rect& b) {

		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = static_cast<int>(a.x);
		rightA = static_cast<int>(a.x + a.w);
		topA = static_cast<int>(a.y);
		bottomA = static_cast<int>(a.y + a.h);

		leftB = static_cast<int>(b.x);
		rightB = static_cast<int>(b.x + b.w);
		topB = static_cast<int>(b.y);
		bottomB = static_cast<int>(b.y + b.h);

		if (bottomA <= topB)
			return false;
		if (topA >= bottomB)
			return false;
		if (rightA <= leftB)
			return false;
		if (leftA >= rightB)
			return false;

		return true;
	}

}

#endif