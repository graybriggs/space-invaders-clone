
#include <SDL.h>
#include <SDL_ttf.h>

#include <algorithm>
#include <string>
#include <vector>

#include "game_score.h"

//#include <iostream>

//constexpr int GameScore::LevelClear = 100;

GameScore::GameScore() :
	current_score(0),
	high_score(666),
	level_number(1),
	level_clear_multiplier(1.0)
{
	//init_digits();
}

GameScore::~GameScore() {

	for (int i = 0; i < digits.size(); ++i) {
		SDL_DestroyTexture(digits[i].texture);
	}
}

void GameScore::enemy_killed(const int score) {
   	current_score += score;
	//std::cout << current_score << std::endl;
}

void GameScore::level_clear() {

	// multiplier starts at 1.0 and increases by 0.1 each clear screen.
	current_score += LevelClear * level_clear_multiplier;

	level_number++;
	level_clear_multiplier += 0.1f;
}


void GameScore::init_digits(SDL_Renderer* renderer) {

	TTF_Font* sans = TTF_OpenFont("Roboto-Black.ttf", 14);
	SDL_Color white = { 255,255,255 };

	int x_pos = 0;

	for (int i = 0; i < 10; ++i) {
		TextEntity te;
		SDL_Surface* surface_si = TTF_RenderText_Solid(sans, std::to_string(i).c_str(), white);
		te.texture = SDL_CreateTextureFromSurface(renderer, surface_si);
		SDL_FreeSurface(surface_si);
		SDL_Rect si_rect;
		si_rect.x = x_pos + i * 16;
		si_rect.y = 16;
		si_rect.w = 16;
		si_rect.h = 16;
		te.rect = si_rect;

		digits[i] = te;
	}
}

void GameScore::update_score(int score) {
	current_score = score;

	if (current_score > INT_MAX) {
		// wraparound ?
		// you broke the score
		// do something special
	}
}

void GameScore::parse_score() {
	score_digits.clear();

	int cur_scr = current_score;

	while (cur_scr > 0) {
		int d = cur_scr % 10;
		score_digits.push_back(d);
		cur_scr = cur_scr / 10;
	}

	std::reverse(std::begin(score_digits), std::end(score_digits));
	
}

void GameScore::render_game_score(SDL_Renderer* renderer) {

	parse_score();

	int x_pos = 0;

	for (int d : score_digits) {

		TextEntity te = digits[d];
		te.rect.x = x_pos;
		x_pos += 16;

		SDL_Rect r = te.rect;
		SDL_RenderCopy(renderer, te.texture, nullptr, &r);
	}

}

void GameScore::render_high_score(SDL_Renderer* renderer) {

}

void GameScore::write_high_score() {

}

void GameScore::read_high_score() {

}
