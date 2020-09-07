#pragma once
#ifndef SPRITE_LOADER_H
#define SPRITE_LOADER_H

#include <SDL.h>
#include <string>
#include "utility.h"

int load_spritesheet(SDL_Renderer* renderer, SDL_Texture** sprite, std::string img_path);


class Sprite {
public:

	Sprite(SDL_Texture* spritesheet);

	// note: A copy constructor is not required because
	// the texture is created outside of the Sprite object.

	~Sprite();
	//SDL_Rect getClipBox() const;
	//void setClipBox(SDL_Rect);
	SDL_Texture* getTexture() const ;
	void setTexture(SDL_Texture* tex);

private:

	//SDL_Rect clip_box; this doesn't work.
	SDL_Texture* texture;
};

#endif