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

	Player(const util::rect& r, const std::string& s);
	virtual ~Player();

	void input(SDL_Event event);
	void logic(double delta);
	void render() const;

	bool fireBullet();

	void incrementScore(int score);

private:

	Direction dir;
	bool fire;
	long playerScore;

};

#endif