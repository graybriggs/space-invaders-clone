#pragma once

#ifndef ENEMY_BOMB_HPP
#define ENEMY_BOMB_HPP

#include "entity.h"

class EnemyBomb : public Entity {

public:
	EnemyBomb(const util::rect& r, const std::string& s);
	virtual ~EnemyBomb();

	void logic(const double delta);
	void render();

private:

	bool isActive;

};

#endif