#include "utility.h"


util::Rect::Rect(float x, float y, int w, int h)
		: pos_x(x), pos_y(y), w(w), h(h)
	{}

SDL_Rect util::Rect::getSDLRect() {
	SDL_Rect r;
	r.x = static_cast<Sint16>(pos_x);
	r.y = static_cast<Sint16>(pos_y);
	r.w = static_cast<Sint16>(w);
	r.h = static_cast<Sint16>(h);
	return r;
}

SDL_Rect util::prepare_rect(int x, int y, int w, int h) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return r;
}