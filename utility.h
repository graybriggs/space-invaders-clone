#pragma once

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <SDL.h>

namespace util {

	// Rect type created to provide a high level of floating point
	// precision over integer whole number precision for moving objects.

	struct Rect {
		Rect();
		Rect(float x, float y, int w, int h);

		SDL_Rect getSDLRect() const;
		util::Rect fromSDLRect(SDL_Rect r);
		float pos_x, pos_y;
		int w, h;
	};

	SDL_Rect prepare_rect(int x, int y, int w, int h);

	// these functions are defined as inline to avoid breaking the
	// C++ "one defintion rule"
	
	inline bool collisionRectScreenLeft(const util::Rect r, int left) {

		int result = static_cast<int>(r.pos_x);

		if (result < left)
			return true;
		else
			return false;
	}

	inline bool collisionRectScreenRight(const util::Rect r, int right) {

		int result = static_cast<int>(r.pos_x + r.w);

		if (result >= right)
			return true;
		else
			return false;
	}

	inline bool collisionRectScreenTop(const util::Rect r, int top) {

		int result = static_cast<int>(r.pos_y);

		if (result < top)
			return true;
		else
			return false;
	}

	inline bool collisionRectScreenBottom(const util::Rect r, int bottom) {

		int result = static_cast<int>(r.pos_y + r.h);

		if (result < bottom)
			return true;
		else
			return false;
	}

	// standard axis aligned collision detection algorithm
	//inline bool aabbCollision(const SDL_Rect a, const SDL_Rect b) {
	inline bool aabbCollision(const util::Rect a, const util::Rect b) {

		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = static_cast<int>(a.pos_x);
		rightA = static_cast<int>(a.pos_x + a.w);
		topA = static_cast<int>(a.pos_y);
		bottomA = static_cast<int>(a.pos_y + a.h);

		leftB = static_cast<int>(b.pos_x);
		rightB = static_cast<int>(b.pos_x + b.w);
		topB = static_cast<int>(b.pos_y);
		bottomB = static_cast<int>(b.pos_y + b.h);

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