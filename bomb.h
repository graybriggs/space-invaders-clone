#pragma once
#ifndef BOMB_H
#define BOMB_H

#include <SDL.h>

#include "entity.h"
#include "utility.h"

class Sprite;

class Bomb : public Entity {
public:

	Bomb(Sprite* sprite, util::Rect pos);
	virtual ~Bomb();

	void setActive();
	void bombDropped(const double x, const double y);
	void logic(const double delta);
	bool isActive() const;

private:

	bool active;
};

#endif
