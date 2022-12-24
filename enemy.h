#pragma once

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.h"
#include "particle_manager.h"

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
	bool canDropBombs();
	void logic(const double delta);

private:

	bool dead;
	bool canDropBomb;

	//ParticleManager particles;
};


#endif