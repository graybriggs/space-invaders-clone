#pragma once

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "sprite.h"
#include "utility.h"

#include <SDL.h>

class Entity {

public:

	Entity(Sprite* s, const util::Rect r);

	void moveTo(const double x, const double y);
	void moveBy(const double x, const double y);
	//SDL_Rect getBoundingBox() const;
	util::Rect getBoundingBox() const;
	Sprite* getSprite();
	SDL_Rect getImageClipBox() const;
	void setImageClipBox(SDL_Rect);

protected:

	SDL_Rect image_clip_box;
	util::Rect bounding_box;
	Sprite* sprite;
};



#endif