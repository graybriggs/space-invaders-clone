#pragma once

#include <SDL.h>
#include <SDL_ttf.h>


#include "text_entity.h"

enum class GameStates;

class Menu {
public:

	Menu(SDL_Renderer* rend);

	GameStates input(SDL_Event e);

	void main_menu();

	TextEntity get_score_text_entity();
	TextEntity get_title_text_entity();
	TextEntity get_start_msg_text_entity();
	TextEntity get_version_text_entity();
private:
	SDL_Renderer* renderer;

	TextEntity score;
	TextEntity title;
	TextEntity start_msg;
	TextEntity version;

};

