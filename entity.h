#pragma once

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "sprite.h"

#include <SDL.h>


class Entity {

public:

	Entity() = delete;
	Entity(Sprite* s, const SDL_Rect r);

	void moveTo(const double x, const double y);
	void moveBy(const double x, const double y);
	SDL_Rect getBoundingBox() const;
	Sprite* getSprite();
	
protected:

	SDL_Rect bounding_box;
	Sprite* sprite;
};



#endif