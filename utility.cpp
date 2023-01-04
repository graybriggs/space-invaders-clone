#include "utility.h"

util::Rect::Rect() {
	pos_x = 0.0;
	pos_y = 0.0;
	w = 0.0;
	h = 0.0;
}

util::Rect::Rect(float x, float y, int w, int h)
		: pos_x(x), pos_y(y), w(w), h(h)
	{}

SDL_Rect util::Rect::getSDLRect() const {
	SDL_Rect r;
	r.x = static_cast<int>(pos_x);
	r.y = static_cast<int>(pos_y);
	r.w = w;
	r.h = h;
	return r;
}

util::Rect util::Rect::fromSDLRect(SDL_Rect r) {
	util::Rect rect(r.x, r.y, r.w, r.h);

	return rect;
}

SDL_Rect util::prepare_rect(int x, int y, int w, int h) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return r;
}