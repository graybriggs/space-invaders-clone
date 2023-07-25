#pragma once

#include <SDL.h>
#include <memory>

struct TextEntity {

	TextEntity() {
		std::memset(&rect, 0, sizeof(SDL_Rect));
		texture = nullptr;
	}

	SDL_Rect rect;
	SDL_Texture* texture;

};