#pragma once

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "sprite.h"
#include "utility.h"

#include <SDL.h>

class Entity {

public:

	Entity(Sprite* s, const util::Rect r);

	virtual void moveTo(const double x, const double y);
	virtual void moveBy(const double x, const double y);
	virtual void setPosition(const double x, const double y);
	virtual void setPosition(const SDL_Rect);
	virtual void setPosition(const util::Rect);
	virtual util::Rect getBoundingBox() const;
	virtual Sprite* getSprite() const;
	virtual SDL_Rect getImageClipBox() const;
	virtual void setImageClipBox(SDL_Rect);
	virtual void setImageClipBox(std::initializer_list<int>);

protected:

	SDL_Rect image_clip_box;
	util::Rect bounding_box;
	Sprite* sprite;
};



#endif