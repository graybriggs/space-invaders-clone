#pragma once
#ifndef SPRITE_LOADER_H
#define SPRITE_LOADER_H


#include <string>

#include <SDL.h>

int load_spritesheet(SDL_Renderer* renderer, SDL_Texture** sprite, std::string img_path);
//int load_spritesheet(SDL_Renderer* renderer, Sprite* sprite, std::string img_path);

class Sprite {
public:

	Sprite();
	Sprite(SDL_Texture* spritesheet, SDL_Rect clip);

	~Sprite();

	SDL_Rect getClipBox();
	SDL_Texture* getTexture();
	void setTexture(SDL_Texture* tex);

private:

	SDL_Rect clip_box;
	SDL_Texture* texture;
};

#endif