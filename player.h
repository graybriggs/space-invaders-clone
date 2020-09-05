#pragma once

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL.h>

#include "utility.h"
#include "entity.h"

#include <string>
#include <iostream>


class Player : public Entity {
public:

	enum Direction { LEFT, RIGHT, STOP };

	Player() = delete;
	Player(Sprite* s, util::Rect start_pos);
	virtual ~Player();

	void input(SDL_Event event);
	void logic(double delta);

	bool hasFired() const;
	void fireWait();
	void canFireOK();

	void incrementScore(int score);

private:

	Direction dir;
	bool canFire;
	bool fire;
	long playerScore;

};

#endif