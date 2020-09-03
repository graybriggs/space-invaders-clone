#pragma once

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SDL.h>

#include <memory>

namespace util {

	SDL_Rect prepare_rect(int x, int y, int w, int h);

	// these functions are defined as inline to avoid breaking the
	// C++ "one defintion rule"
	
	inline bool collisionRectScreenLeft(const SDL_Rect r, int left) {

		int result = static_cast<int>(r.x);

		if (result < left)
			return true;
		else
			return false;
	}

	inline bool collisionRectScreenRight(const SDL_Rect r, int right) {

		int result = static_cast<int>(r.x + r.w);

		if (result >= right)
			return true;
		else
			return false;
	}

	// standard axis aligned collision detection algorithm
	inline bool aabbCollision(const SDL_Rect a, const SDL_Rect b) {

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