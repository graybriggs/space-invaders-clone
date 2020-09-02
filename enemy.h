#pragma once

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.h"
#include "enemy_bomb.h"

#include <memory>
#include <iostream>

class Enemy : public Entity {

public:

	Enemy(const util::rect& r, const std::string& s, int scoreVal);
	//Enemy(int x, int y, int w, int h, std::string s);
	virtual ~Enemy();

	void setDead();
	void setAlive();
	bool isDead() const;
	void setCanDropBombs(bool b);
	int getValue();
	bool canEnemyDropBomb();
	//
	void dropBomb();
	//
	void logic(const double delta);
	void render() const;

public:

	int value;
	bool dead;
	bool canDropBombs;
	std::shared_ptr<EnemyBomb> bomb;

};

#endif