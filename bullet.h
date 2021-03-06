#pragma once

#ifndef BULLET_HPP
#define BULLET_HPP

#include "entity.h"
#include "utility.h"
#include <string>


class Bullet : public Entity {

public:

	Bullet(Sprite* s, util:: Rect start_pos);
	virtual ~Bullet();

	//void fire(SDL_Rect r);
	void fire(util::Rect r);
	bool isActive() const;
	void setInactive();
	void setPosition(util::Rect);
	//void setPosition(SDL_Rect);
	void logic(const double delta);

private:
	void reset();

	bool bulletActive;
};



#endif