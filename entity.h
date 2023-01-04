#pragma once

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "sprite.h"
#include "utility.h"

#include <SDL.h>

class Entity {

public:

	Entity(Sprite* s, const util::Rect r);
	virtual ~Entity();

	void moveTo(const double x, const double y);
	void moveBy(const double x, const double y);
	void setPosition(const double x, const double y);
	void setPosition(const SDL_Rect);
	void setPosition(const util::Rect);
	util::Rect getBoundingBox() const;
	Sprite* getSprite() const;
	SDL_Rect getImageClipBox() const;
	void setImageClipBox(SDL_Rect);
	void setImageClipBox(std::initializer_list<int>);

protected:

	SDL_Rect image_clip_box;
	util::Rect bounding_box;
	Sprite* sprite;
};



#endif