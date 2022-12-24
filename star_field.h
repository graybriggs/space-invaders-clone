#pragma once

#include "SDL.h"

#include "utility.h"
#include "renderer.h"

#include <vector>

constexpr int NUM_FORE_STARS = 32;
constexpr int NUM_BACK_STARS = 96;


struct Starfield {
	std::vector<util::Rect> fore_stars;
	std::vector<util::Rect> back_stars;
};

void setup_starfield(Starfield& starfield);
void render_starfield(SDL_Renderer* renderer, Starfield& starfield);
void update_starfield(Starfield& starfield, const double delta);