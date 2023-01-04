#pragma once
#ifndef SPRITE_LOADER_H
#define SPRITE_LOADER_H

#include <SDL.h>

#include <memory>
#include <string>

#include "utility.h"


class Sprite {
public:

	Sprite(SDL_Texture* spritesheet);

	// note: A copy constructor is not required because
	// the texture is created outside of the Sprite object.

	~Sprite();
	SDL_Texture* getTexture() const ;
	void setTexture(SDL_Texture* tex);

private:

	//SDL_Rect clip_box; this doesn't work.
	SDL_Texture* texture;
};


int load_spritesheet(SDL_Renderer* renderer, SDL_Texture** sprite, std::string img_path);
std::unique_ptr<Sprite> load_sprite(SDL_Renderer* renderer, std::string path);

#endif