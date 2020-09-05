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
	
protected:

	util::Rect bounding_box;
	//SDL_Rect bounding_box;
	Sprite* sprite;
};



#endif