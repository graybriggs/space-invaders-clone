#include "star_field.h"

#include "globals.h"


void setup_starfield(Starfield& stars) {

	for (int i = 0; i < NUM_FORE_STARS; i++) {
		
		util::Rect star(rand() % global::SCREEN_W, rand() % global::SCREEN_H, 2, 2);
		stars.fore_stars.push_back(star);
	}
	for (int i = 0; i < NUM_BACK_STARS; i++) {

		util::Rect star(rand() % global::SCREEN_W, rand() % global::SCREEN_H, 2, 1);
		stars.back_stars.push_back(star);
	}
}

void render_starfield(SDL_Renderer* renderer, Starfield& starfield) {

	SDL_Color c;
	c.r = 0xFF;
	c.g = 0xFF;
	c.b = 0xFF;
	c.a = 0xFF;

	for (auto& s : starfield.fore_stars) {
		render_rect(renderer, s.getSDLRect(), c);
	}
	for (auto& s : starfield.back_stars) {
		render_rect(renderer, s.getSDLRect(), c);
	}
}

void update_starfield(Starfield& starfield, const double delta) {

	// scroll stars horizontally for now.

	for (auto& s : starfield.fore_stars) {
		s.pos_x -= 0.3 * delta;
		if (s.pos_x < 0)
			s.pos_x = global::SCREEN_W;
	}

	for (auto& s : starfield.back_stars) {
		s.pos_x -= 0.1 * delta;
		if (s.pos_x < 0)
			s.pos_x = global::SCREEN_W;
	}
}