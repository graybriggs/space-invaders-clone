
#include "menu.h"

#include "globals.h"
#include "state.h"

#include <string>

Menu::Menu(SDL_Renderer* rend)
{
	renderer = rend;

	TTF_Font* sans = TTF_OpenFont("sans.ttf", 14);
	SDL_Color white = { 255,255,255 };



	SDL_Surface* surface_si = TTF_RenderText_Solid(sans, "SPACE INVADERS: ", white);
	title.texture = SDL_CreateTextureFromSurface(renderer, surface_si);
	SDL_FreeSurface(surface_si);
	SDL_Rect si_rect;
	si_rect.x = 196;
	si_rect.y = 128;
	si_rect.w = 618;
	si_rect.h = 320;
	title.rect = si_rect;


	SDL_Surface* surface_score = TTF_RenderText_Solid(sans, "HI-SCORE: ", white);
	score.texture = SDL_CreateTextureFromSurface(renderer, surface_score);
	SDL_FreeSurface(surface_score);
	SDL_Rect score_rect;
	score_rect.x = 32;
	score_rect.y = global::SCREEN_H - 48;
	score_rect.w = 96;
	score_rect.h = 32;
	score.rect = score_rect;


	SDL_Surface* surface_start = TTF_RenderText_Solid(sans, "Press SPACE or ENTER to start: ", white);
	start_msg.texture = SDL_CreateTextureFromSurface(renderer, surface_start);
	SDL_FreeSurface(surface_start);
	SDL_Rect start_rect;
	start_rect.x = 196;
	start_rect.y = 256;
	start_rect.w = 320;
	start_rect.h = 32;
	score.rect = score_rect;
	start_msg.rect = start_rect;


	std::string ver_str = "Version: " + std::to_string(global::VERSION_MAJOR) + "." + std::to_string(global::VERSION_MINOR);
	SDL_Surface* surface_version = TTF_RenderText_Solid(sans, ver_str.c_str(), white);
	version.texture = SDL_CreateTextureFromSurface(renderer, surface_version);
	SDL_FreeSurface(surface_version);
	SDL_Rect ver_rect;
	ver_rect.x = global::SCREEN_W - 64;
	ver_rect.y = 32;
	ver_rect.w = 48;
	ver_rect.h = 32;
	version.rect = ver_rect;

}

GameStates Menu::input(SDL_Event e) {


	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_KP_ENTER) {
			return GameStates::GAME;
		}
	}
	return GameStates::MENU;
}

void Menu::main_menu() {


}

TextEntity Menu::get_score_text_entity() {
	return score;
}

TextEntity Menu::get_title_text_entity() {
	return title;
}

TextEntity Menu::get_start_msg_text_entity() {
	return score;
}

TextEntity Menu::get_version_text_entity() {
	return title;
}