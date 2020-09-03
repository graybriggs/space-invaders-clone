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
	Player(Sprite* s, SDL_Rect start_pos);
	virtual ~Player();

	void input(SDL_Event event);
	void logic(double delta);

	bool fireBullet();

	void incrementScore(int score);

private:

	Sprite* s;
	Direction dir;
	bool fire;
	long playerScore;

};

#endif