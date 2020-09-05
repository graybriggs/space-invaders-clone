#pragma once

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.h"

#include <memory>
#include <iostream>

struct util::Rect;
class EnemyBomb;

class Enemy : public Entity {

public:

	Enemy(Sprite* s, util::Rect pos);

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

public:

	int value;
	bool dead;
	bool canDropBombs;

};

class BonusEnemy {


private:
	Enemy enemy;
};

#endif